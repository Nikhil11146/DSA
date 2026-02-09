#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct stack {
    node *top;
} stack;

void init(stack *s);
int isEmpty(stack *s);
int isFull(stack *s);
int push(stack *s, int data);
int pop(stack *s, int *data);
int peek(stack *s, int *data);