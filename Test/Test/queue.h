#include "gba.h"

#define obj point

struct queue {
    obj* arr;
    int head;
    int length;
    int capacity;
}; typedef struct queue queue;

void push(queue &q, obj o);
obj pop(queue &q);