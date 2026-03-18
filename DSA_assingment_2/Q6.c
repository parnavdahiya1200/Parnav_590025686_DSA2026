#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create circular list
void create(int n) {
    struct Node *temp, *newNode;
    for (int i = 0; i < n; i++) {
        newNode = malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);

        if (head == NULL) {
            head = temp = newNode;
            newNode->next = head;
        } else {
            temp->next = newNode;
            newNode->next = head;
            temp = newNode;
        }
    }
}

// Insert at beginning
void insertBegin(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Delete beginning
void deleteBegin() {
    if (head == NULL) return;

    struct Node* temp = head;
    struct Node* last = head;

    while (last->next != head)
        last = last->next;

    if (head == head->next) {
        head = NULL;
    } else {
        head = head->next;
        last->next = head;
    }

    free(temp);
}

// Delete end
void deleteEnd() {
    if (head == NULL) return;

    struct Node *temp = head, *prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
        head = NULL;
    else
        prev->next = head;

    free(temp);
}

// Display and count
void display() {
    if (head == NULL) return;

    struct Node* temp = head;
    int count = 0;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    } while (temp != head);

    printf("(back to head)\n");
    printf("Total nodes = %d\n", count);
}

int main() {
    create(4);
    insertBegin(5);
    insertEnd(50);
    deleteBegin();
    deleteEnd();
    display();
    return 0;
}

