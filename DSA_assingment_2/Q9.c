#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coeff, exp;
    struct Node* next;
};

struct Node* head = NULL;

// Insert term at end
void insert(int c, int e) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display polynomial
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Evaluate polynomial
int evaluate(int x) {
    struct Node* temp = head;
    int result = 0;

    while (temp != NULL) {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }
    return result;
}

int main() {
    insert(5, 2);
    insert(3, 1);
    insert(7, 0);

    display();

    int x;
    printf("Enter value of x: ");
    scanf("%d", &x);

    printf("Result = %d\n", evaluate(x));
    return 0;
}
