#include "header.h"

int main() {
    node *p;
    init(&p);
    print(p);
    insert(&p, 20, 10);
    insert(&p, 10, 10);
    insert(&p, 10, 20);
    insert(&p, 30, 20);
    destroy(&p);
    print(p);
}