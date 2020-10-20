#include "gfx.h"
#include "screenmode.h"
#include "keypad.h"
#include "mode4.h"

// Simple snake game
// Movement is stepwise one renderSize at the time 
// for optimized rendering, screen is divided in 
// a grid, and two rectangles do not overlap unless
// they have the same coordinate

void snake();
bool hitFood(point head, point food);
bool hitBorder(point head, int border, int renderSize);
bool hitTail(point *snake, u16 length, u16 head);
void placeFood(point *snake, u16 length, int renderSize, point *food);

int main()
{
	SeedRandom();
	init();

	setPalette(1, WHITE);
	setPalette(0, BLACK);

    setPalette(2, rgb15(31, 0, 0)); // RED
    setPalette(3, rgb15(0, 31, 0)); // GREEN
    setPalette(4, rgb15(0, 0, 31)); // BLUE
    setPalette(5, rgb15(31, 31, 0)); // YELLOW
    setPalette(6, rgb15(31, 0, 31)); // PINK
    setPalette(7, rgb15(0, 31, 31)); // CYAN

    snake();

    while (1);
}

void snake() {
    int colBorder = 4;
    int colBg = 0;
    int colFood = 1;
    int colSnake = 3;

    // SNAKE

    // ---------------------------------------
    // Draw border
    int border = 5;
    point crnr = {0, 0};
    drawRect(crnr, WIDTH, border, colBorder);
    crnr.y = HEIGHT - border;
    drawRect(crnr, WIDTH, border, colBorder);
    crnr.y = border;
    drawRect(crnr, border, HEIGHT - 2*border, colBorder);
    crnr.x = WIDTH - border;
    drawRect(crnr, border, HEIGHT - 2*border, colBorder);
    vid_flip();
    crnr.x = 0;
    crnr.y = 0;
    drawRect(crnr, WIDTH, border, colBorder);
    crnr.y = HEIGHT - border;
    drawRect(crnr, WIDTH, border, colBorder);
    crnr.y = border;
    drawRect(crnr, border, HEIGHT - 2*border, colBorder);
    crnr.x = WIDTH - border;
    drawRect(crnr, border, HEIGHT - 2*border, colBorder);
    vid_flip();
    // --------------------------------------

    // snake as circle buffer, allocate memory for maximum sized snake
    int renderSize = 5;
    point tail[322];
    u16 head = 0;
    u16 sLength = 1;

    // Food on a random position
    point food = {RAND(6)*renderSize + WIDTH/2 - 3*renderSize, RAND(6)*renderSize + HEIGHT/2 - 3*renderSize};
    bool ateFood = false;

    point p = {border, border};
    point er[] = {p, p};

    tail[0] = p;
    // wait for button press
    // ...

    int dx = 0;
    int dy = 0;
    forever {
        vid_flip(); // Flip page, display what was rendered last frame
        // Clear after tail
        drawRect(er[0], renderSize, renderSize, 0);
        if (!ateFood)
            drawRect(er[1], renderSize, renderSize, 0);
        // Pause keypress
        // ...

        // Keys input, set direction
        if (KEY_PRESSED(KEY_UP)) {
            // ...
            dy = -1;
            dx = 0;
        }
        else if (KEY_PRESSED(KEY_DOWN)) {
            // ...
            dy = 1;
            dx = 0;
        }
        else if (KEY_PRESSED(KEY_LEFT)) {
            // ...
            dy = 0;
            dx = -1;
        }
        else if (KEY_PRESSED(KEY_RIGHT)) {
            // ...
            dy = 0;
            dx = 1;
        }

        // Move in direction
        tail[0].y += dy*renderSize;
        tail[0].x += dx*renderSize;
        er[0] = er[1];
        er[1] = tail[(head - 1) % sLength];
        drawRect(tail[0], renderSize, renderSize, 2);

        // Check if hit food, if so add to length and respawn food
        // ...
        if (hitFood(tail[0], food)) {
            placeFood(tail, sLength, renderSize, &food);
            ateFood = true;
            sLength++;
        }

        drawRect(food, renderSize, renderSize, 5);


        if (hitBorder(tail[head], border, renderSize)) {
            vid_flip();
            return;
        }

        Sleep(60);
    }
}

bool hitFood(point head, point food) {
    return head.x == food.x && head.y == food.y;
}
bool hitBorder(point head, int border, int renderSize) {
    return head.x == border - renderSize || head.x == WIDTH - border || head.y == border - renderSize || head.y == HEIGHT - border;
}
bool hitTail(point *snake, u16 length, u16 head) {
    point h = snake[head];
    int i;
    for (i = 1; i < length; i++) {
        point t = snake [(head + i) % length];
        if (h.x == t.x && h.y == t.y) {
            return false;
        }
    }
    return true;
}
void placeFood(point *snake, u16 length, int renderSize, point *food) {
    while (1) {
        food->x = (int)(RAND(6)*renderSize + WIDTH/2 - 3*renderSize);
        food->y = (int)(RAND(6)*renderSize + HEIGHT/2 - 3*renderSize);
        int i;
        for (i = 0; i < length; i++) {
            if (snake[i].x == food->x && snake[i].y == food->y) {
                continue;                
            }
        }
        break;
    }
}
