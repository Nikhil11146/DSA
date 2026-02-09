#include "header.h"

void init(queue *q) {
    q->front = -1;
    q->rear = -1;
}

int enqueue(queue *q, int val) {
    if (q->rear == CAP - 1) {
        return 0;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear++;
    q->arr[q->rear] = val;
    return 1;
}

int dequeue(queue *q, int *val) {
    if (q->front == -1 || q->front > q->rear) {
        return 0;
    }

    *val = q->arr[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }

    return 1;
}

int peekFront(queue *q, int *val) {
    if (q->front == -1) {
        return 0;
    }

    *val = q->arr[q->front];
    return 1;
}

int peekRear(queue *q, int *val) {
    if (q->rear == -1) {
        return 0;
    }

    *val = q->arr[q->rear];
    return 1;
}
