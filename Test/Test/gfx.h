// Gfx.h created 30 Nov 2001
// Desc: Store some of the main graphics routines used by the game


#ifndef GFX_H
#define GFX_H

#include "gba.h"
#include <stdbool.h>

// First, some general utilities

// GBA stores 15 bit color in blue green red format meaing first 5 
// bits are red, next five green, next blue. What is the 16bit?
#define rgb15(r,g,b) ((r)+((g)<<5)+((b)<<10)) 
#define WHITE 0xffff
#define BLACK 0

#define forever while(1)

// do some looping so the gba will wait
// 125 is a good delay for displaying something
// 1 is a good delay for a game (like 30/60 fps) or something like that
void Sleep(int i);

// The following code for random was taken from Mines10.zip of gbadev.org, that author
// had the following comment in it:
// random stuff extracted from an email from 'ninge1'
#define RAND_MAX 32767
volatile s32 RAND_RandomData;

void SeedRandom(void);

s32 RAND(s32 Value);

//usage somwhere in program SeedRandom();
//then xrand = RAND(MAX_X); where MAX_X is range upper bound for value you want returned!

// Simple graphics methods that are independent of screen mode
// Point in two dimentions
struct point {
	int x, y;
};
typedef struct point point;

bool pointEquals(point a, point b);
// Return the inverse point (x to y and y to x)
point inverse(point pt);

#endif

