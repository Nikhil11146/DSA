#include "header.h"

void init(node **h) {
    *h = NULL;
}

int insertNode(node **h, int val, int pos) {
    node *p = *h;
    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = val;
    if(p == NULL) {
        *h = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        return 1;
    }

    for(int i = 0; i < pos - 2 && p->next != NULL; i++, p = p->next);

    if(pos == 1) {
        *h = newNode;
    } else {
        if(p->next)p->next->prev = newNode;
        newNode->next = p->next;
    }
    p->next  = newNode;
    newNode->prev = p;
    return 1;
}

int searchNode(node *h, int val, int *pos) {
    node *p = h;
    if(h == NULL) return 0;
    
    for(int i = 0; p != NULL; p = p->next, i++) {
        if(p->val == val) {
            *pos = i + 1;
            return 1;
        }
    }
    return 0;
}

int deleteNode(node **h, int val) {
    node *p = *h, *temp;
    if(*h == NULL) return 0;
    
    for(int i = 0; p != NULL; p = p->next, i++) {
        if(p->val == val) {
            if(p == *h) {
                *h = p->next;
            } else {
                temp = p->prev;
                temp->next = p->next;
            }
            if(p->next)p->next->prev = p->prev;
            free(p);
            return 1;
        }
    }
    return 0;
}

void print(node *h) {
    for(node *p = h; p; p = p->next) {
        printf("%d ", p->val);
    }
    printf("\n");
}