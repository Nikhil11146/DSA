#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
} node;

typedef struct stack {
    node *top;
} stack;

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

int push(stack *s, char data) {
    if(isFull(s)) return 0;
    node *p = (node*) malloc(sizeof(node));
    p->data = data;
    p->next = s->top;
    s->top = p;
    return 1;
}

int pop(stack *s, char *data) {
    if(isEmpty(s)) return 0;
    node *temp = s->top;
    *data = temp->data;
    s->top = temp->next;
    free(temp);
    return 1;
}

int peek(stack *s, char *data) {
    if(isEmpty(s)) return 0;
    *data = s->top->data;
    return 1;
}

int isAlphaNum(char c) {
    if(c <= '9' && c >= '0') return 1;
    if(c <= 'z' && c >= 'a') return 1;
    if(c >= 'A' && c <= 'Z') return 1;
    return 0;
}

int priority(char c) {
    switch (c){
        case '^': return 5;
        case '/': return 4;
        case '*': return 4;
        case '+': return 3;
        case '-': return 3;
        case '(': return 2;
    }
    return -1;
}

char* infixToPostfix(char *infix) {
    stack s;
    init(&s);
    int i =0; char c;
    char *postfix = (char*) malloc(strlen(infix) + 1);
    while(*infix) {
        if(isAlphaNum(*infix)) {
            postfix[i++] = *infix;
        } else if(*infix == '('){
            push(&s, *infix);
        } else if(*infix == ')') {
            while (!isEmpty(&s)) {
                pop(&s, &c);
                if (c == '(') break;
                postfix[i++] = c;
            }
        } else {
            while (!isEmpty(&s)) {
                peek(&s, &c);
                if (priority(c) >= priority(*infix)) {
                    pop(&s, &c);
                    postfix[i++] = c;
                } else {
                    break;
                }
            }
            push(&s, *infix);
        }
        infix++;
    }

    while(!isEmpty(&s)) {
        pop(&s, &c);
        postfix[i++] = c;
    }
    postfix[i] = '\0';
    return postfix;
}

int main() {
    char infix[100];
    
    printf("Enter Infix: ");
    scanf("%s", infix);

    char *postfix = infixToPostfix(infix);
    printf("%s", postfix);
}