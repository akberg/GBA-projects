// Implementation of gfx.h stuff

#include "screenmode.h"
#include "gfx.h"
#include <math.h>

// used to slow down the gba between frames, and for displaying stuff pretty cool eh?
void Sleep(int i)
{
	int x, y;
	int c = 0;
	for (y = 0; y < i; y++)
	{
		for (x = 0; x < 30000; x++)
			c = c + 2; // do something to slow things down
	}
}

void SeedRandom(void)
{
   RAND_RandomData = REG_VCOUNT;
}


s32 RAND(s32 Value)
{
   RAND_RandomData *= 20077;
   RAND_RandomData += 12345;

   return ((((RAND_RandomData >> 16) & RAND_MAX) * Value) >> 15);
}

bool pointEquals(point a, point b)
{
	return a.x == b.x && a.y == b.y;
}

point inverse(point pt) {
	point n = { pt.y, pt.x };
	return n;
}
