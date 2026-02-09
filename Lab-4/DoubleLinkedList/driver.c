#include "header.h"

int main() {
    node *h = NULL;
    int *pos;
    init(&h);

    insertNode(&h, 100, 1);
    insertNode(&h, 200, 2);
    insertNode(&h, 230, 22);
    insertNode(&h, 20, 2);
    // deleteNode(&h, 100);
    // deleteNode(&h, 200);
    deleteNode(&h, 230);
    print(h);
    if(searchNode(h, 1070, pos))printf("%d", *pos);
}