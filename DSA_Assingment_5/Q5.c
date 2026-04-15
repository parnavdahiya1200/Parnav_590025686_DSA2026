// 5. Write a C program to implement non-recursive tree traversal using stack  

//(i) Inorder  
//(ii) Preorder  
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

struct node* stack[100];
int top=-1;

void push(struct node *root)
{
    stack[++top]=root;
}

struct node* pop()
{
    return stack[top--];
}

int empty()
{
    return top==-1;
}

void inorder(struct node *root)
{
    struct node *curr=root;

    while(curr||!empty())
    {
        while(curr)
        {
            push(curr);
            curr=curr->left;
        }

        curr=pop();
        printf("%d ",curr->data);
        curr=curr->right;
    }
}

void preorder(struct node *root)
{
    push(root);

    while(!empty())
    {
        struct node *curr=pop();
        printf("%d ",curr->data);

        if(curr->right)
            push(curr->right);

        if(curr->left)
            push(curr->left);
    }
}

int main()
{
    struct node *root=create();

    inorder(root);
    printf("\n");
    preorder(root);
}
