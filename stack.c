#include<stdio.h>
#include<stdlib.h>
#define CAP 100
struct stack
{
    int arr[CAP][2];
    int top;
};

int isFull(struct stack *s)
{
    return s->top == CAP-1;
}

int isEmpty(struct stack *s)
{
    return s->top == -1;
}
void init(struct stack *s)
{
    s->top = -1;
}

int push(struct stack *s, int x, int y)
{
    if(isFull(s))return 0;
    s->arr[++(s->top)][0] = x;
    s->arr[s->top][1] = y;
    return 1;
}

int pop(struct stack *s, int *x, int *y)
{
    printf("Entered with top = %d\n", s->top);
    if(isEmpty(s))return 0;
    *x = s->arr[s->top][0];
    *y = s->arr[(s->top)--][1];
    printf("Exited with top = %d\n", s->top);
    return 1;
}

void stack_print(struct stack *s)
{
    for(int i=s->top; i>=0; i--)
    {
        printf("%d, %d\n", s->arr[i][0], s->arr[i][1]);
    }
    printf("\n");
    printf("Top = %d\n",s->top); 
}

