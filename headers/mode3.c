#include "mode3.h"
#include <math.h>

void init()
{
	REG_DISPCNT = MODE_3 | BG2_ENABLE;
}

u16 *pixel(u8 x, u8 y)
{
	if (x > WIDTH || y > HEIGHT)
		return 0;
	return &(VideoBuffer)[x + y * WIDTH];
}

void clearScreen()
{
	int i;
	for (i = 0; i < WIDTH * HEIGHT; i++) {
		(VideoBuffer)[i] = 0x0;
	}
}

void drawPixel(u8 x, u8 y, u16 color) 
{
	*pixel(x, y) = color;
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
	s16 dy = round((p2.x - p1.x) / (p2.y - p1.y) * n/4);

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
