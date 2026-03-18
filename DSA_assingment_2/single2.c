#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, i, value, pos = 1, found = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Search element
    printf("Enter element to search: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element found at position %d", pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
        printf("Element does not exist");

    return 0;
}
