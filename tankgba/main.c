/*
Tank Ravagers by Loirak Development

Programming: Ben Rhoades (benr@loirak.com)

Compiler Setup 30 Nov 2001
Programming 1 Dec 2001 (from 9pm-2:30am)
Artwork by Joe McCombs 1996-ish, but hey its a game!

Thanks go out to:
Dovoto : The Pern Project
gbadev.org
devrs.com
Visoly/Lik-Sang!

*/
#include "gba.h"
#include "screenmode.h"
#include "keypad.h"
#include "gfx.h"
#include "gfx\logo.h" //header file created by pcx2gba
#include "gfx\tank.h"
#include "gfx\text.h"
#include "gfx\objects.h"
#include "gfx\star.h"

#define NUM_BOMBS		4

// some memory location defines
u16* FrontBuffer = (u16*)0x6000000;
u16* BackBuffer = (u16*)0x600A000;
u16* videoBuffer;
volatile u16* ScanlineCounter = (volatile u16*)0x4000006;

u16* paletteMem = (u16*)0x5000000;	//PalMemory is 256 16 bit BGR values starting at 0x5000000

//function prototypes

// Mode 4 is 240(120)x160 by 8bit
void PlotPixel(int x,int y, unsigned short int c)	
{ 
	videoBuffer[(y) *120 + (x)] = (c); 
}

// Mode 4 is 240(120)x160 by 8bit
void PlotPixelTransparent(int x,int y, unsigned short int c)	
{ 
	unsigned short int temp;
	if ((c & 0x00FF) == 0) // bottom is transparent
	{
		if ((c & 0xFF00) == 0) // top is also transparent
			return;
		// so bottom transparent, top is not so....
		temp = ((videoBuffer[(y) * 120 + (x)]) & 0x00FF);
		temp |= c; // or it with c (to get the highpart of c in
		videoBuffer[(y) *120 + (x)] = (temp);
	}
	else
	if 	((c & 0xFF00) == 0) // only the top is transprent
	{
		temp = ((videoBuffer[(y) * 120 + (x)]) & 0xFF00);
		temp |= c;
		videoBuffer[(y) *120 + (x)] = (temp);
	}
	else // no part is transparent
		videoBuffer[(y) *120 + (x)] = (c); 
}

void EraseScreen(void);		// erases the screen in mode4
void DoIntro(void);			// display the loirak screen, and sleep for a second or two
void DisplayTank(void);		// the titlescreen/menu
void WaitForStart(void);	// waits for the start key to be pressed
void Flip(void);			// flips between the back/front buffer
void WaitForVblank(void);	// waits for the drawer to get to end before flip

void DrawBackground(void);							// draws the starish background
void ChangeBackPal(void);							// changes to the star palette
void DrawLife(int life);							// draws the life status bar
void DrawTank(int tankx, int tanky, int direction);	// draws the tank on the screen
void DrawBombs(int bx[NUM_BOMBS], int by[NUM_BOMBS],// draws the bombs
			   int bs[NUM_BOMBS]);
void DrawDied(void);								// draws you died on bg, wait for start

int main(void)
{
	// for some wierd reason this GCC has to have variable decalared before any statements?

	SetMode(MODE_4 | BG2_ENABLE ); //set mode 4

	EraseScreen();
	DoIntro();

	while (1) // always stay in this loop
	{
		int life;	// life of the tank between 38 and 0
					// since the area(status bar) on the star.pcx from 
					// 186,35 -> 224,43 has width of 8
		int loop;
		int bombx[NUM_BOMBS];
		int bomby[NUM_BOMBS];
		int bombs[NUM_BOMBS]; // status of the bombs 1 on, 0 off
		int tankx, tanky;
		int rnum; // temp storage of random number
		int score;

		EraseScreen();
		DisplayTank();
		// they pressed start so lets play the game, and when they die it will erase
		// the screen and do the menu again

		ChangeBackPal(); // switch to the star palette


		tankx = 0;		
		tanky = 153-objtank_HEIGHT;
		for (loop = 0; loop < NUM_BOMBS; loop++)
		{
			bombs[NUM_BOMBS] = 0; // set the status of the bombs to off
		}
		life = 38;
		score = 0;
		while (life > 0)
		{
			// prolly want to do a screen flip here for speed????
			// anyhow method is as follows
			// 1. draw the bg
			// 2. draw the bombs, life, tank
			// 3. flip it to the screen
			// check for user input
			// move the bombs
			// check for collision
			// subtract from life

			DrawBackground();
			DrawLife(life);
			DrawTank(tankx, tanky, 0);
			DrawBombs(bombx, bomby, bombs);
			//DrawScore(score); // not implemented
			WaitForVblank();
			Flip();

			// tank movement

			if (! ((*KEYS) & KEY_RIGHT) )
				tankx+=2;
			if (! ((*KEYS) & KEY_LEFT) )
				tankx-=2;
			// boundary checking for tank
			if (tankx < 0) tankx = 0;
			if (tankx > (180-objtank_WIDTH)/2 ) tankx = (180 - objtank_WIDTH)/2;

			// bomb movement and collision dectection and life removal
			for(loop = 0; loop < NUM_BOMBS; loop++)
			{
				// if off then random to turn it on
				if (bombs[loop] == 0) 
				{
					rnum = RAND(10);
					if (rnum == 4) 
					{
						bombs[loop] = 1; // turn it on					
						bombx[loop] = RAND((180-objbomb_WIDTH)/2);
						bomby[loop] = 0;
					}
				}
				// move the bombs
				if (bombs[loop] == 1) 
				{
					bomby[loop] += 2; // its on so move it
				
					// its on, so check for collision
					if (bomby[loop] > (180-objtank_WIDTH)) // at the bottom
					{
						if ( (  ( bombx[loop]+(objbomb_WIDTH/2))  > tankx) &&
							(bombx[loop] < (tankx+objtank_WIDTH/2))) // collision
							life -= 4;
						bombs[loop] = 0; // turn the bomb off
						score += 1;
					}
				}

			} // end for bombs

			//Sleep(1); // slow things down a bit
			
		} // end while life > 0

		DrawBackground(); // draw the bg, 
		DrawDied();
		
		// draw you died, and press start, and wait for the start key

	} // end while(1)
	return 0;
} // end Agbmain


void EraseScreen(void)
{
	int x,y;
	for(y = 0; y < 160; y++)
	{
		for(x = 0; x < 120; x++)

		{
			PlotPixel(x,y,0x0000);//logoData contains the color values of your pict
			
		}
	}
	WaitForVblank();
	Flip();
}

void DoIntro(void)
{
	int x, y;
	for(x = 0; x < 256; x++)
		paletteMem[x] = logoPalette[x];	//loop through and store the palette from your pict 
									//palette into video palette mem 
	for(y = 0; y < 160; y++)
	{
		for(x = 0; x < 120; x++)

		{
			PlotPixel(x,y,logoData[y*120+x]);//logoData contains the color values of your pict
			
		}
	}
	WaitForVblank();
	Flip();
	Sleep(125);
}

void DisplayTank(void)
{
	int x, y;
	
	// set the palette
	for(x = 0; x < 256; x++)
		paletteMem[x] = tankPalette[x];	//loop through and store the palette from your pict 
									//palette into video palette mem 

	// draw the picture
	for(y = 0; y < 160; y++)
	{
		for(x = 0; x < 120; x++)

		{
			PlotPixel(x,y,tankData[y*120+x]);//logoData contains the color values of your pict
			
		}
	}
	WaitForVblank();
	Flip();
	Sleep(50);

	// put the start text on top of it

	// draw the picture
	for(y = 0; y < 160; y++)
		for(x = 0; x < 120; x++)
			PlotPixel(x,y,tankData[y*120+x]);//logoData contains the color values of your pict

	// draw the text
	for(y = 0; y < txstart_HEIGHT; y++)
		for (x = 0; x < (txstart_WIDTH/2); x++)
			PlotPixel(x+58, y+10, txstartData[y*(txstart_WIDTH/2)+x]);
	WaitForVblank();
	Flip();

	WaitForStart();

}

void WaitForStart(void)
{
	while (1) // loops infinitely till they press start
		if (! ((*KEYS) & KEY_START) )
			return;
}

void Flip(void)			// flips between the back/front buffer
{
	if(REG_DISPCNT & BACKBUFFER) //back buffer is the current buffer so we need to switch it to the font buffer
	{ 
		REG_DISPCNT &= ~BACKBUFFER; //flip active buffer to front buffer by clearing back buffer bit
		videoBuffer = BackBuffer; //now we point our drawing buffer to the back buffer
    }
    else //front buffer is active so switch it to backbuffer
    { 
		REG_DISPCNT |= BACKBUFFER; //flip active buffer to back buffer by setting back buffer bit
		videoBuffer = FrontBuffer; //now we point our drawing buffer to the front buffer
	}
}

void WaitForVblank(void)	// waits for the drawer to get to end before flip
{
	while(*ScanlineCounter < 160) {	// do nothing
	}//now we are in the vblank period
}

void ChangeBackPal(void)							// changes to the star palette
{
	int x;
	// set the palette
	for(x = 0; x < 256; x++)
		paletteMem[x] = starPalette[x];	//loop through and store the palette from your pict 
									//palette into video palette mem 
}


void DrawBackground(void)								// draws the starish background
{
	int x, y;
	// draw the picture
	for(y = 0; y < 160; y++)
	{
		for(x = 0; x < 120; x++)

		{
			PlotPixel(x,y,starData[y*120+x]);//logoData contains the color values of your pict
			
		}
	}
}

void DrawLife(int life)							// draws the life status bar
{
	int x, y;
	for (x = 186; x < (life+186); x+=2)
		for (y = 35; y < 43; y++)
			PlotPixel(x/2, y, 0x0202); // green pal[2]
	for (x = 186+life; x < 224; x+=2)
		for (y = 35; y < 43; y++)
			PlotPixel(x/2, y, 0xBCBC); // red pal[188] ; d188 = xBC
}

void DrawTank(int tankx, int tanky, int direction)	// draws the tank on the screen
{
	int x, y;
	// draw the tank
	for(y = 0; y < objtank_HEIGHT; y++)
		for (x = 0; x < (objtank_WIDTH/2); x++)
			PlotPixelTransparent(x+tankx, y+tanky, objtankData[y*(objtank_WIDTH/2)+x]);
}

void DrawBombs(int bx[NUM_BOMBS], int by[NUM_BOMBS], int bs[NUM_BOMBS])
{
	int x, y, loop;
	for(loop=0; loop < NUM_BOMBS; loop++)
		if (bs[loop]) // draw it if its on
			for(y = 0; y < objbomb_HEIGHT; y++)
				for (x = 0; x < (objbomb_WIDTH/2); x++)
					PlotPixelTransparent(x+bx[loop], y+by[loop], objbombData[y*(objbomb_WIDTH/2)+x]);
}


void DrawDied(void)
{
	int x, y;
	// draw you died!
	for(y = 0; y < txdied_HEIGHT; y++)
		for (x = 0; x < (txdied_WIDTH/2); x++)
			PlotPixelTransparent(x+20, y+10, txdiedData[y*(txdied_WIDTH/2)+x]);
	// draw press start!
	for(y = 0; y < txstart_HEIGHT; y++)
		for (x = 0; x < (txstart_WIDTH/2); x++)
			PlotPixelTransparent(x+20, y+40, txstartData[y*(txstart_WIDTH/2)+x]);

	WaitForVblank();
	Flip();

	WaitForStart();
}
