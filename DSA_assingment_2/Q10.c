#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// chut.
struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student* next;
};

struct Student* head = NULL;

// Insert record
void insert() {
    struct Student* newNode = malloc(sizeof(struct Student));

    printf("Enter Roll Name Marks: ");
    scanf("%d %s %f", &newNode->roll, newNode->name, &newNode->marks);

    newNode->next = head;
    head = newNode;
}

// Display records
void display() {
    struct Student* temp = head;

    while (temp != NULL) {
        printf("Roll:%d Name:%s Marks:%.2f\n",
               temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}

// Search record
void search(int roll) {
    struct Student* temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Found: %s %.2f\n", temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }
    printf("Record not found\n");
}

// Delete record
void deleteRecord(int roll) {
    struct Student *temp = head, *prev = NULL;

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

int main() {
    int ch, roll;

    do {
        printf("\n1.Insert 2.Display 3.Search 4.Delete 5.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3:
                printf("Enter roll: ");
                scanf("%d", &roll);
                search(roll);
                break;
            case 4:
                printf("Enter roll: ");
                scanf("%d", &roll);
                deleteRecord(roll);
                break;
        }
    } while (ch != 5);

    return 0;
}
