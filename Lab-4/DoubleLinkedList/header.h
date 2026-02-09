#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
    struct node *prev;
} node;

void init(node **h);
void print(node *h);
int insertNode(node **h, int val, int pos);
int searchNode(node *h, int val, int *pos);
int deleteNode(node **h, int val);

