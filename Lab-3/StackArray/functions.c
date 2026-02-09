#include "header.h"

void init(stack *s) {
    s->top = -1;
}


int isEmpty(stack *s) {
    if(s->top == -1) return 1;
    return 0;
}
int isFull(stack *s) {
    if(s->top == CAP) return 1;
    return 0;
}
int push(stack *s, int data) {
    if(isFull(s)) return 0;
    s->arr[++(s->top)] = data;
    return 1;
}
int pop(stack *s, int *data) {
    if(isEmpty(s)) return 0;
    *data = s->arr[(s->top)--];
    return 1;
}
int peek(stack *s, int *data) {
    if(isEmpty(s)) return 0;
    *data = s->arr[(s->top)];
    return 1;
}