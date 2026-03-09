#include "header.h"

void init(node **l) {
    *l =  NULL;
}

void print(node *l) {
    node *p = l;
    if(p == NULL) return;

    do {
        printf("%d ", p->data);
        p = p->next;
    }while(p != l);
    printf("\n");
}

int insert(node **l, int data, int key) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    if(*l == NULL) {
        temp->next = temp;
        *l = temp;
        return 1;
    };
    node *p = *l;

    do {
        if(p->data == key) {
            temp->next = p->next;
            p->next = temp;
            return 1;
        }
        p = p->next;
    }while(p != *l);
    free(temp);
    return 0;
}

int deleteNode(node **l, int data) {
    node *p = *l;
    if(p == NULL) return 0;
    do {
        if(p->next->data == data) {
            node *t = p->next;
            if(p->next == *l) {
                if(p->next == p) *l = NULL;
                else *l = p->next->next;
            }
            p->next = p->next->next;
            free(t);
            return 1;
        }
        p = p->next;
    }while(p->next != (*l)->next);
    return 0;
}

int destroy(node **l) {
    if (*l == NULL)
        return 0;

    node *curr = (*l)->next;

    while (curr != *l) {
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(*l);
    *l = NULL;

    return 1;
}