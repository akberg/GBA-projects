// mode4.h
// Mode 4 specific graphics methods

#ifndef MODE_4_
#define MODE_4_

#define HEIGHT	160
#define WIDTH	240

#include "gba.h"
#include "gfx.h"
#include "screenmode.h"


// Dependent of screen mode
//-------------------------------------
// Initialize REG_DISPCNT to mode 4
void init();

volatile u16* write_page;

// Page flip
void vid_flip();
// Returns the adress of a pixel
u16* pixel(u8 x, u8 y);
// Set a palette color
void setPalette(u8 id, u16 color);
// Fill screen
void fillScreen(u8 clrid);
// Clear screen (fill black)
void clearScreen();
//-------------------------------------

// Simple graphics
// Draw one pixel
void drawPixel(u8 x, u8 y, u8 clrid);
// Check if a point is in screen
bool onScreen(point pt);
// Draw point if it's on screen
void drawPoint(point pt, u8 clrid);
// Calculate a point on a straight line rounded to pixels
point onLine(point p1, point p2, s16 n);
// Draw a straight line between two points
void drawLine(point start, point end, u8 clrid);
// Draw a regular rectangle
void drawRect(point ul, int width, int height, u8 clrid);

#endif
