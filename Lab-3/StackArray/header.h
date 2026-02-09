#include <stdio.h>
#define CAP 1000

typedef struct stack{
    int arr[CAP];
    int top;
} stack;

void init(stack *s);
int isEmpty(stack *s);
int isFull(stack *s);
int push(stack *s, int data);
int pop(stack *s, int *data);
int peek(stack *s, int *data);