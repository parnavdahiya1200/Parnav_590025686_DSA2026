# 1. Write a C program to create a binary tree using an array.  
The program should support the following operations:  
(i) Insert elements into the tree  
(ii) Display the tree elements  
(iii) Display the parent, left child, and right child of a given node  

```c
#include <stdio.h>
#define MAX 100

int tree[MAX];
int n = 0;

void insert(int value)
{
    if (n >= MAX)
    {
        printf("Tree is full\n");
        return;
    }
    tree[n] = value;
    n++;
}

void display()
{
    for (int i = 0; i < n; i++)
        printf("%d ", tree[i]);
}

void findNode(int value)
{
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (tree[i] == value)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Node not found\n");
        return;
    }

    if (index == 0)
        printf("No Parent\n");
    else
        printf("Parent: %d\n", tree[(index - 1) / 2]);

    if (2 * index + 1 < n)
        printf("Left Child: %d\n", tree[2 * index + 1]);

    if (2 * index + 2 < n)
        printf("Right Child: %d\n", tree[2 * index + 2]);
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1.Insert 2.Display 3.Find 4.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanf("%d", &value);
            insert(value);
            break;

        case 2:
            display();
            break;

        case 3:
            scanf("%d", &value);
            findNode(value);
            break;

        case 4:
            return 0;
        }
    }
}
