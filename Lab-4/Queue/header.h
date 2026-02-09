#include <stdio.h>
#define CAP 1000

typedef struct queue {
    int arr[CAP];
    int front, rear;
} queue;

void init(queue *q);
int enqueue(queue *q, int val);
int dequeue(queue *q, int *val);
int peekFront(queue *q, int *val);
int peekRear(queue *q, int *val);