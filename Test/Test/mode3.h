// mode3.h
// Mode 3 specific graphics methods

#ifndef MODE_3_
#define MODE_3_

#define HEIGHT	160
#define WIDTH	240

#include "gba.h"
#include "gfx.h"
#include "screenmode.h"


// Dependent of screen mode
//-------------------------------------
// Initialize REG_DISPCNT to mode 3
void init();

// Returns the adress of a pixel
u16* pixel(u8 x, u8 y);
// Clear screen
void clearScreen();
//-------------------------------------

// Simple graphics
// Draw one pixel
void drawPixel(u8 x, u8 y, u16 color);
// Check if a point is in screen
bool onScreen(point pt);
// Draw point if it's on screen
void drawPoint(point pt, u16 color);
// Calculate a point on a straight line rounded to pixels
point onLine(point p1, point p2, s16 n);
// Draw a straight line between two points
void drawLine(point start, point end, u16 color);

#endif
