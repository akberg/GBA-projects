#include "gba.h"
#include "gfx.h"
#include "keypad.h"

#define WIDTH   240
#define HEIGHT  160

u16* vid_page = VideoBuffer;


void vid_flip() {
    vid_page = (u16*)((u32)vid_page ^ 0xa0000);
    REG_DISPCNT ^ 0x4;
}

void plot_pixel(u16 x, u16 y, u8 clrid) {
    // Reminder that GBA doesn't allow byte writes, only 16 bit word writes
    u16* dst = &vid_page[(y * WIDTH + x) / 2];
    if (x&1) {
        *dst = (*dst & 0xff) | (clrid<<8);  // Odd pixel
    } else {    
        *dst = (*dst &~0xff) | clrid;       // Even pixel
    }
}


int main() {
    REG_DISPCNT = 0x404; // bg2 vmode 4

    (BGPaletteMem)[1] = 0xffff;
    (BGPaletteMem)[2] = RGB(255, 0, 0);
    (BGPaletteMem)[3] = RGB(0, 255, 0);

    plot_pixel(100, 100, 2);
    plot_pixel(100, 101, 2);
    vid_flip();
    plot_pixel(100, 100, 3);
    plot_pixel(100, 101, 3);

    while (1) {
        vid_flip();
    }

    return 0;
}
