#include "mode4.h"
#include <math.h>

void init()
{
	REG_DISPCNT = MODE_4 | BG2_ENABLE;
	write_page = (u16*)((u32)VideoBuffer ^ 0xa000);
	// Fill palette with some standard colours?

}


void vid_flip() 
{
	write_page = (u16*)((u32)write_page ^ 0xa000);
	REG_DISPCNT ^= 0x10;
}


u16 *pixel(u8 x, u8 y)
{
	if (x > WIDTH || y > HEIGHT)
		return 0;
	return (u16*)&(write_page)[x + y * WIDTH / 2];
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
			drawPixel(j, i, clrid);
	}
}

void clearScreen()
{
	fillScreen(0);
}

void drawPixel(u8 x, u8 y, u8 clrid)
{
    // Cannot write in byte sized chunks. 
    u16 *dst= &(write_page)[(y*WIDTH+x)/2];  // Division by 2 due to u8/u16 pointer mismatch!
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



void drawPoint(point pt, u8 clrid)
{
    if (pt.x >= 0 && pt.y >= 0 && pt.x <= WIDTH && pt.y <= HEIGHT)
	    drawPixel(pt.x, pt.y, clrid);
}

point onLine(point p1, point p2, s16 n)
{
	s16 x = p1.x + (p2.x - p1.x > 0 ? n : -n);
	s16 dy = round((p2.x - p1.x) / (p2.y - p1.y) * n / 4);

	point out = { x, p1.y + dy };
	return out;
}

void drawLine(point start, point end, u8 clrid)
{
    if (start.x > end.x) {

        point tmp = start;
        start = end;
        end = start;
    }
	int lengthx = end.x - start.x;
	int lengthy = end.y - start.y;

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
			drawPoint(next, clrid);
		}
	}
    else if (!lengthx) 
    {
        // Vertical line
        for (i = 0; i <= abs(lengthy); i++) 
        {
            point next = {
                start.x,
                start.y + (lengthy > 0 ? i : -i)
            };
            drawPoint(next, clrid);
        }
    }
    else if (!lengthy)
    {
        // Horizontal line
        for (i = 0; i <= abs(lengthx); i++) 
        {
            point next = {
                start.x + (lengthx > 0 ? i : -i),
                start.y
            };
            drawPoint(next, clrid);
        }
    }
    else 
    {
        int dx = abs(lengthx);
        int sx = (lengthx > 0 ? 1 : -1);
        int dy = -abs(lengthy);
        int sy = (lengthy > 0 ? 1 : -1);
        int err = dx + dy;
        int x = start.x;
        int y = start.y;
        while (1)
        {
            drawPixel(x, y, clrid);
            if (x == end.x && y == end.y) break;
            int err2 = 2*err;
            if (err2 >= dy)
            {
                err += dy;
                x += sx;
            }
            if (err2 <= dx)
            {
                err += dx;
                y += sy;
            }
        }
    }
}


void drawRect(point ul, int width, int height, u8 clrid)
{
    int endX = ul.x + width-1;
    int i;
    for (i = 0; i<height; i++)
    {
        point p = {endX, ul.y};
        drawLine(ul, p, clrid);
        ul.y += 1;
    }
}
