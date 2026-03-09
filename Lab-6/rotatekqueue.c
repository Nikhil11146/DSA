#include <stdio.h>
#define CAP 1000

typedef struct queue {
    int arr[CAP];
    int front, rear;
} queue;

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

void initq(queue *q) {
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

int isEmptyQ(queue *q) {
    if(q->front == -1) return 1;
    return 0;
}

int main() {
    queue q;
    queue res;
    stack s;

    init(&s);
    initq(&q);
    initq(&res);
    
    int n = 7, a, k = 4;
    printf("k: \n");
    scanf("%d", &k);
    printf("n: \n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        enqueue(&q, a);
    }

    for(int i = 0; i < k; i++) {
        dequeue(&q, &a);
        push(&s, a);
    }

    while(!isEmpty(&s)) {
        pop(&s, &a);
        enqueue(&res, a);
    }

    while(!isEmptyQ(&q)) {
        dequeue(&q, &a);
        enqueue(&res, a);
    }

    while(!isEmptyQ(&res)) {
        dequeue(&res, &a);
        printf("%d ", a);
    }
}