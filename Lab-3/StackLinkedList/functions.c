#include "header.h"

void init(stack *s) {
    s->top = NULL;
}

int isEmpty(stack *s) {
    if(s->top == NULL) return 1;
    return 0;
}

int isFull(stack *s) {
    node *p = (node*) malloc(sizeof(node));
    if(!p) return 1;
    free(p);
    return 0;
}

int push(stack *s, int data) {
    if(isFull(s)) return 0;
    node *p = (node*) malloc(sizeof(node));
    p->data = data;
    p->next = s->top;
    s->top = p;
    return 1;
}

int pop(stack *s, int *data) {
    if(isEmpty(s)) return 0;
    node *temp = s->top;
    *data = temp->data;
    s->top = temp->next;
    free(temp);
}

int peek(stack *s, int *data) {
    if(isEmpty(s)) return 0;
    *data = s->top->data;
    return 1;
}