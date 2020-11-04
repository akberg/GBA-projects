//#include "gfx.h"
#include "screenmode.h"
#include "keypad.h"
#include "mode4.h"
// Simple snake game
// Movement is stepwise one renderSize at the time 
// for optimized rendering, screen is divided in 
// a grid, and two rectangles do not overlap unless
// they have the same coordinate
const int tick = 50;
const int speed = 40;// ticks per movement
const double period = 0.06104; // ms per counter increment

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

    /* Clock init */
    REG_TM0CNT = 0b10000001;
    //              ^     ^^ 1024 cycles per counter increment @
    //              ^ Timer Enable

    snake();

    while (1);
}

void snake() {
    enum Dir { UP, DOWN, LEFT, RIGHT, PAUSE };
    enum Dir direction = PAUSE;

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
    u16 maxLength = 322;
    point tail[322];
    u16 head = 0;
    u16 prevHead = 0;
    u16 back = 0;
    u16 nBack = 0; // next to back
    u16 sLength = 1;

    // Food on a random position
    point food = {RAND(6)*renderSize + WIDTH/2 - 3*renderSize, RAND(6)*renderSize + HEIGHT/2 - 3*renderSize};
    int ateFood = 1;

    point p = {border, border};
    point er[] = {p, p};

    tail[head] = p;
    // wait for button press
    // ...

    int dx = 0;
    int dy = 0;
    int i = 0;
    for(;;i++) {

        // Keys input, set direction
        if (KEY_PRESSED(KEY_UP) && direction != DOWN) {
            // ...
            dy = -1;
            dx = 0;
            direction = UP;
        }
        else if (KEY_PRESSED(KEY_DOWN) && direction != UP) {
            // ...
            dy = 1;
            dx = 0;
            direction = DOWN;
        }
        else if (KEY_PRESSED(KEY_LEFT) && direction != RIGHT) {
            // ...
            dy = 0;
            dx = -1;
            direction = LEFT;
        }
        else if (KEY_PRESSED(KEY_RIGHT) && direction != LEFT) {
            // ...
            dy = 0;
            dx = 1;
            direction = RIGHT;
        }

        // Clear after tail
        // drawRect(er[0], renderSize, renderSize, colBg);
        // if (ateFood)
        //     ateFood--;
        // else if (sLength > 1)
        //     drawRect(er[1], renderSize, renderSize, colBg);
        // Pause keypress
        // ...

        if (i == 5 * speed) {
            vid_flip(); // Flip page, display what was rendered last frame
            // Move in direction
            //tail[0].y += dy*renderSize;
            //tail[0].x += dx*renderSize;
            i = 0;
            // new solution:

            /* Move head forwards */
            prevHead = head;
            head = (head+1)%maxLength;
            tail[head] = (point){0, 0};
            tail[head].y = tail[prevHead].y + dy*renderSize;
            tail[head].x = tail[prevHead].x + dx*renderSize;

            /* Detect collisions */
            // Check if hit food, if so add to length and respawn food
            // ...
            if (hitFood(tail[head], food)) {
                placeFood(tail, sLength, renderSize, &food);
                ateFood = 2;
                sLength++;
            }        
            if (hitBorder(tail[head], border, renderSize)) {
                // Set gameover and draw last frame
                vid_flip();
                return;
            }

            /* move tail if no growth */
            if (!ateFood) {
                back = nBack;
                nBack = (nBack+1)%maxLength;
                er[0] = er[1];
                er[1] = tail[nBack];
            } else { ateFood--; }

            /* draw */
            drawRect(er[0], renderSize, renderSize, colBg);
            drawRect(er[1], renderSize, renderSize, colBg);
            drawRect(tail[head], renderSize, renderSize, 2);
            if (sLength > 1)
                drawRect(tail[prevHead], renderSize, renderSize, 2);
            
            drawRect(food, renderSize, renderSize, 5);
        }

        while (REG_TM0D < 64500) {
            asm("nop");
        }
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
        point t = snake [(head - i) % length];
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
