#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* head = NULL;

// Create list
void create(int n) {
    struct Node *temp, *newNode;
    for (int i = 0; i < n; i++) {
        newNode = malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = newNode->prev = NULL;

        if (head == NULL)
            head = temp = newNode;
        else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
}

// Insert beginning
void insertBegin(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Insert end
void insertEnd(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert after given value
void insertAfter(int key, int val) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) return;

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;


    temp->next = newNode;
}

// Delete beginning
void deleteBegin() {
    if (head == NULL) return;

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

// Delete end
void deleteEnd() {
    if (head == NULL) return;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

// Delete given value
void deleteValue(int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Traversal forward
void displayForward() {
    struct Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nCount = %d\n", count);
}

// Traversal backward
void displayBackward() {
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    create(4);
    insertBegin(5);
    insertEnd(50);
    insertAfter(5, 10);
    deleteBegin();
    deleteEnd();
    displayForward();
    displayBackward();
    return 0;
}
