#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void reverseData(struct Node* head) {
    int arr[100], i = 0;
    struct Node* temp = head;

    // Store data in array
    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    temp = head;

    // Put data back in reverse order
    while (temp != NULL) {
        temp->data = arr[--i];
        temp = temp->next;
    }
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *a, *b, *c;

    a = malloc(sizeof(struct Node));
    b = malloc(sizeof(struct Node));
    c = malloc(sizeof(struct Node));

    a->data = 10; a->next = b;
    b->data = 20; b->next = c;
    c->data = 30; c->next = NULL;

    reverseData(a);
    display(a);

    return 0;
}
