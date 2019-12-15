#include "mode4.h"
#include <math.h>

void init()
{
	REG_DISPCNT = MODE_4 | BG2_ENABLE;
	write_page = VideoBuffer;
	// Fill palette with some standard colours?

}


u16 *vid_flip() 
{
	write_page = write_page == VideoBuffer ? (VideoBuffer + 0xa000) : VideoBuffer;
	REG_DISPCNT ^= REG_DISPSTAT;
}


u16 *pixel(u8 x, u8 y)
{
	if (x > WIDTH || y > HEIGHT)
		return 0;
	return &(VideoBuffer)[x + y * WIDTH / 2];
}


void setPalette(u8 id, u16 color)
{
	(BGPaletteMem)[id] = color;
}


void fillScreen(u8 clrid) 
{
	u16 i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++)
			drawPixel(i, j, clrid);
	}
}

void clearScreen()
{
	fillScreen(0);
}

void drawPixel(u8 x, u8 y, u8 clrid)
{
	// Cannot write in byte sized chunks. 
	u16 *dst= &write_page[(y*WIDTH+x)/2];  // Division by 2 due to u8/u16 pointer mismatch!
    if(x&1)
        *dst= (*dst& 0xFF) | (clrid<<8);    // odd pixel
    else
        *dst= (*dst&~0xFF) |  clrid;
}

bool onScreen(point pt)
{
	return pt.x >= 0 &&
		pt.x < WIDTH &&
		pt.y >= 0 &&
		pt.y < HEIGHT;
}



void drawPoint(point pt, u16 color)
{
	drawPixel(pt.x, pt.y, color);
}

point onLine(point p1, point p2, s16 n)
{
	s16 x = p1.x + (p2.x - p1.x > 0 ? n : -n);
	s16 dy = round((p2.x - p1.x) / (p2.y - p1.y) * n / 4);

	point out = { x, p1.y + dy };
	return out;
}

void drawLine(point start, point end, u16 color)
{
	const s16 lengthx = end.x - start.x;
	const s16 lengthy = end.y - start.y;

	s16 i;
	if (abs(lengthx) == abs(lengthy))
	{
		// Diagonal line
		for (i = 0; i <= abs(lengthx); i++)
		{
			point next = {
				start.x + (lengthx > 0 ? i : -i),
				start.y + (lengthy > 0 ? i : -i)
			};
			drawPoint(next, color);
		}
	}
	else if (abs(lengthx) > abs(lengthy))
	{
		// Draw y = f(x)
		for (i = 0; i <= abs(lengthx); i++)
		{
			drawPoint(onLine(start, end, i), color);
		}
	}
	else
	{
		// Draw x = f(y)
		for (i = 0; i <= abs(lengthy); i++)
		{
			drawPoint(inverse(onLine(inverse(start), inverse(end), i)), color);
		}
	}
}
