#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
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
            newNode->next = newNode->prev = head;
        } else {
            newNode->prev = temp;
            newNode->next = head;
            temp->next = newNode;
            head->prev = newNode;
            temp = newNode;
        }
    }
}

// Insert beginning
void insertBegin(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode->prev = head;
        return;
    }

    struct Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    head = newNode;
}

// Insert end
void insertEnd(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode->prev = head;
        return;
    }

    struct Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}

// Delete beginning
void deleteBegin() {
    if (head == NULL) return;

    struct Node* last = head->prev;
    struct Node* temp = head;

    if (head->next == head)
        head = NULL;
    else {
        head = head->next;
        head->prev = last;
        last->next = head;
    }

    free(temp);
}

// Delete end
void deleteEnd() {
    if (head == NULL) return;

    struct Node* last = head->prev;

    if (head->next == head)
        head = NULL;
    else {
        last->prev->next = head;
        head->prev = last->prev;
    }

    free(last);
}

// Display and count
void display() {
    if (head == NULL) return;

    struct Node* temp = head;
    int count = 0;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    } while (temp != head);

    printf("\nCount = %d\n", count);
}

int main() {
    create(3);
    insertBegin(5);
    insertEnd(50);
    deleteBegin();
    deleteEnd();
    display();
    return 0;
}
