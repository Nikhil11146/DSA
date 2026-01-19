#include "header.h"

int insert(struct Node **h, int data) {
    struct Node *p = *h, *pre = NULL;
    struct Node *new = (struct Node * )malloc(sizeof(struct Node));
    new->data = data;
    
    while(p != NULL && p->data < data) {
        pre = p;
        p = p->next;
    }

    new->next = p;

    if(pre == NULL) {
        *h = new;  
    } else {
        pre->next = new;
    }
    
    return 1;
}

int search(struct Node *h, int target, struct Node *res) {
    if(h == NULL) {
        printf("Empty List");
        return 0;
    }
    struct Node *p = h;

    while(p != NULL && p->data < target) {
        p = p->next;
    }
    if(p->data == target){
        res = p;
        printf("%d\n", res->data);
        return 1;
    } else {
        printf("Not Found");
        return 0;
    }
    return 1;    
}

int delete(struct Node **h, int data) {
    if(h == NULL) {
        printf("Empty List");
        return 0;
    }
    struct Node *p = *h, *pre = NULL;

    while(p != NULL && p->data < data) {
        pre = p;
        p = p->next;
    }

    if(p->data == data){
        if(pre ==  NULL) {
            *h = p->next;
        } else {
            pre->next = p->next;
        }
        free(p);
        return 1;
    } else {
        printf("Not Found");
        return 0;
    }
};

void destroy(struct Node **h) {
    struct Node *p = *h, *temp = NULL;
    while(p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
    *h = NULL;
}

void print_list(struct Node *h) {
    if(h == NULL) {
        printf("Empty List");
    };

    struct Node *p = h;
    
    while(p != NULL) {
        printf("%d \t", p->data);
        p = p->next;
    }
    printf("\n");
}