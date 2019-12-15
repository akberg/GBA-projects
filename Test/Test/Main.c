
#include "gfx.h"
#include "screenmode.h"
#include "keypad.h"
#include "mode4.h"

// Defines in 
//const s32 HEIGHT	= 160;
//const s32 WIDTH	= 240;


//unsigned short* screen;

int main()
{
	SeedRandom();

	//*(unsigned long*)0x4000000 = 0x403;	// Mode 3, bg2 on
	//SetMode(0x403);
	init();

	// Defined as VideoBuffer
	//unsigned short* screen = (unsigned short*)0x6000000;	// VRAM address
	
	setPalette(0, WHITE);
	setPalette(1, BLACK);

	fillScreen(0);
	vid_flip();
	//fillScreen(1);

	
	forever
	{
		// (3) Count 60 frames, then flip pages
		u8 ii = 0;
        if(++ii == 60)
        {   
            ii=0;   
			
            vid_flip(); 
		}
	}
}
