#include<stdio.h>
#include<stdlib.h>

typedef struct BinaryTree
{
    int data;
    struct BinaryTree *left_child, *right_child;
}BT;

BT* newNode(int data)
{
    BT *tempNode = (BT*)malloc(sizeof(BT));
    tempNode->data = data;
    tempNode->left_child = tempNode->right_child = NULL;
    return tempNode;
}

void preOrderTraversal(BT *root)
{
    if(root)
    {
        printf("%d ",root->data);
        preOrderTraversal(root->left_child);
        preOrderTraversal(root->right_child);
    }
}

void inOrderTraversal(BT *root)
{
    if(root)
    {
        inOrderTraversal(root->left_child);
        printf("%d ",root->data);
        inOrderTraversal(root->right_child);
    }
}

void postOrderTraversal(BT *root)
{
    if(root)
    {
        postOrderTraversal(root->left_child);
        postOrderTraversal(root->right_child);
        printf("%d ",root->data);
    }
}

void main()
{
    BT *root = newNode(1);
    root->left_child = newNode(2);
    root->right_child = newNode(3);
    root->left_child->left_child = newNode(4);
    root->left_child->right_child = newNode(5);
    root->right_child->left_child = newNode(6);
    root->right_child->right_child = newNode(7);

    printf("PreOrderTraversal:\t");
    preOrderTraversal(root);printf("\n");

    printf("InOrderTraversal:\t");
    inOrderTraversal(root);printf("\n");

    printf("PostOrderTraversal:\t");
    postOrderTraversal(root);
}
