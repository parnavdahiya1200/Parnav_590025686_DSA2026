#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
        head = NULL;
    else
        prev->next = NULL;

    free(temp);
}

// Delete after given value
void deleteAfter(int key) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Deletion not possible\n");
        return;
    }

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

// Display list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating sample list
    struct Node *n1, *n2, *n3, *n4;

    n1 = malloc(sizeof(struct Node));
    n2 = malloc(sizeof(struct Node));
    n3 = malloc(sizeof(struct Node));
    n4 = malloc(sizeof(struct Node));

    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = n4;
    n4->data = 40; n4->next = NULL;

    head = n1;

    deleteBeginning();
    deleteEnd();
    deleteAfter(20);

    display();

    return 0;
}
