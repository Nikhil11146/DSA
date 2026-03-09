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

    // If tree is empty, create node
    if (*root == NULL) {
        node *temp = (node*)malloc(sizeof(node));
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;

        *root = temp;
        return;
    }

    // Go to left subtree
    if (val < (*root)->val) {
        insert(&((*root)->left), val);
    }

    // Go to right subtree
    else if (val > (*root)->val) {
        insert(&((*root)->right), val);
    }
}

int main() {
    node *r = NULL;
    int arr[] = {10, 30, 50, 20, 60, 100};
    for(int i = 0; i < 6; i++) {
        insert(&r, arr[i]);
    }

    int t = 0, l = 0;
    traverse(r, &t, &l);
    printf("%d %d %d\n", t, l, t - l);
}