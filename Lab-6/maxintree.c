#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left, *right;
} node;

void traverse(node *r, int *t, int *l) {
    if(!r) return;
    
    (*t)++;
    traverse(r->left, t, l);
    traverse(r->right, t, l);
    if(!(r->left) && !(r->right)) (*l)++;
}

void insert(node **root, int val) {

    if (*root == NULL) {
        node *temp = (node*)malloc(sizeof(node));
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;

        *root = temp;
        return;
    }

    if (val < (*root)->val) {
        insert(&((*root)->left), val);
    }

    else if (val > (*root)->val) {
        insert(&((*root)->right), val);
    }
}

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

void maxNode(node *r, int *m) {
    if(!r) return;
    
    *m = max(*m, r->val);
    maxNode(r->left, m);
    maxNode(r->right, m); 
}

int main() {
    node *r = NULL;
    int arr[] = {10, 30, 500, 20, 60, 100};
    for(int i = 0; i < 6; i++) {
        insert(&r, arr[i]);
    }

    int m = 0;
    maxNode(r, &m);

    printf("%d\n", m);
}