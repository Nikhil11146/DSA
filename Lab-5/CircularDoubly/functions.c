#include "header.h"

void init(struct Node* head) {
    head = NULL;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

int isEmpty(struct Node* head) {
    return head == NULL;
}

void insertNode(struct Node* head, int targetKey, int newKey, int insertAfter) {
    struct Node* newNode = createNode(newKey);

    if (isEmpty(head)) {
        head = newNode;
        head->next = head;
        head->prev = head;
        printf("List empty. Initialized with %d.\n", newKey);
        return;
    }

    struct Node* temp = head;
    struct Node* targetNode = NULL;

    do {
        if (temp->data == targetKey) {
            targetNode = temp;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (targetNode == NULL) {
        printf("Target %d not found.\n", targetKey);
        free(newNode);
        return;
    }

    if (insertAfter) {
        struct Node* nextNode = targetNode->next;
        
        newNode->next = nextNode;
        newNode->prev = targetNode;
        targetNode->next = newNode;
        nextNode->prev = newNode;
        printf("Inserted %d AFTER %d.\n", newKey, targetKey);
    } 
    else {
        struct Node* prevNode = targetNode->prev;
        
        newNode->next = targetNode;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        targetNode->prev = newNode;
        
        if (targetNode == head) {
            head = newNode;
        }
        printf("Inserted %d BEFORE %d.\n", newKey, targetKey);
    }
}

void deleteKey(struct Node* head, int key) {
    if (isEmpty(head)) {
        printf("List is empty.\n");
        return;
    }

    struct Node* curr = head;
    int found = 0;

    do {
        if (curr->data == key) {
            found = 1;
            break;
        }
        curr = curr->next;
    } while (curr != head);

    if (!found) {
        printf("Key %d not found.\n", key);
        return;
    }

    if (curr->next == curr) {
        free(curr);
        head = NULL;
        printf("Deleted %d. List is now empty.\n", key);
        return;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    if (curr == head) {
        head = curr->next;
    }

    free(curr);
    printf("Deleted %d.\n", key);
}

void traverse(struct Node* head, int forward) {
    if (isEmpty(head)) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    
    if (forward) {
        printf("Forward: ");
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("(HEAD)\n");
    } else {
        printf("Backward: ");
        temp = head->prev;
        do {
            printf("%d -> ", temp->data);
            temp = temp->prev;
        } while (temp != head->prev); 
        printf("(TAIL)\n");
    }
}

void destroyList(struct Node** head) {
    if (isEmpty(*head)) return;

    struct Node* curr = (*head)->next;
    while (curr != *head) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(*head);
    *head = NULL;
    printf("List destroyed.\n");
}