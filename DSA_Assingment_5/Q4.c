
//# 4. Write a C program to perform Level Order Traversal on a binary
// tree using a queue  


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create()
{
    int x;
    scanf("%d",&x);

    if(x==-1)
        return 0;

    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=x;

    newnode->left=create();
    newnode->right=create();

    return newnode;
}

struct node* queue[100];
int front=-1,rear=-1;

void enqueue(struct node *root)
{
    if(front==-1)
        front=0;
    queue[++rear]=root;
}

struct node* dequeue()
{
    return queue[front++];
}

void levelorder(struct node *root)
{
    enqueue(root);

    while(front<=rear)
    {
        struct node *temp=dequeue();
        printf("%d ",temp->data);

        if(temp->left)
            enqueue(temp->left);

        if(temp->right)
            enqueue(temp->right);
    }
}

int main()
{
    struct node *root=create();
    levelorder(root);
}
