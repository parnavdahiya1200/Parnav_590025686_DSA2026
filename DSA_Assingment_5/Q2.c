//# 2. Write a C program to create a binary tree using linked list representation and perform various operations  

//(i) Total number of nodes  
//(ii) Number of leaf nodes  
//(iii) Height of tree  
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
    scanf("%d", &x);

    if(x == -1)
        return 0;

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = x;

    newnode->left = create();
    newnode->right = create();

    return newnode;
}

int count(struct node *root)
{
    if(root == NULL)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

int leaf(struct node *root)
{
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    return leaf(root->left) + leaf(root->right);
}

int height(struct node *root)
{
    if(root == NULL)
        return 0;

    int l = height(root->left);
    int r = height(root->right);

    return (l>r?l:r)+1;
}

int main()
{
    struct node *root = create();

    printf("Total Nodes=%d\n",count(root));
    printf("Leaf Nodes=%d\n",leaf(root));
    printf("Height=%d",height(root));
}

