#include <stdio.h>

typedef struct stack {
    int arr[1000];
    int top;
} stack;

void init(stack *s) {
    s->top = -1;
}

int isEmpty(stack *s) {
    if(s->top == -1) return 1;
    return 0;
}
int isFull(stack *s) {
    if(s->top == 1000) return 1;
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

int main() {
    char s[1000];
    char bo[] = "({[";
    char bc[] = ")}]";
    stack st;
    init(&st);

    printf("Enter Exp: ");
    scanf("%s", s);

    for(int i = 0; s[i]; i++) {
        for(int j = 0; j < 3; j++) {
            if(s[i] == bo[j]) {
                push(&st, bo[j]);
                break;
            } else if(s[i] == bc[j]) {
                int a;
                if(isEmpty(&st)) {
                    printf("INCORRECT \n");
                    return 0;
                }
                pop(&st, &a);
                if(a != '(') {
                    printf("INCORRECT \n");
                    return 0;
                }
                break;
            }
        }
    }

    if(!isEmpty(&st)) printf("INCORRECT \n");
    else printf("CORRECT \n");
}