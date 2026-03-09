#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;


void init(node **l);
void print(node *l);
int insert(node **l, int data, int key);
int deleteNode(node **l, int data);
int destroy(node **l);
