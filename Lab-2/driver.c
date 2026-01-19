#include "header.h"

int main() {
    struct Node *head = NULL, *res = NULL;
    print_list(head);
    insert(&head, 10);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 0);
    insert(&head, -10);
    print_list(head);
    search(head, 10, res);
    delete(&head, 10);
    print_list(head);
    destroy(&head);
    print_list(head);
}