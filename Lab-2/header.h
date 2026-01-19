#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int insert(struct Node **h, int data);
int delete(struct Node **h, int data);
int search(struct Node *h, int target, struct Node *res);
void destroy(struct Node **h);
void print_list(struct Node *h);