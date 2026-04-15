//# 3. Write a C program to implement recursive tree traversals  

//(i) Inorder  
//(ii) Preorder  
//(iii) Postorder  

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

void inorder(struct node *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main()
{
    struct node *root=create();

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
}

