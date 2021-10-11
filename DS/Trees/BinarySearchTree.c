#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySearchTree
{
    int data;
    struct BinarySearchTree *left_child, *right_child;
}BST;

BST* newNode(int data)
{
    BST *tempNode = (BST*)malloc(sizeof(BST));
    tempNode->data = data;
    tempNode->left_child = tempNode->right_child = NULL;
    return tempNode;
}

BST* iterativeInsertion(BST* root, int key)
{
    BST *temp = root;
    while(1)
    {
        if(key < temp->data)
        {
            if(temp->left_child == NULL)
            {
                temp->left_child = newNode(key);
                break;
            }
            temp = temp->left_child;
        }
        else if(key > temp->data)
        {
            if(temp->right_child == NULL)
            {
                temp->right_child = newNode(key);
                break;
            }
            temp = temp->right_child;
        }
    }
}

BST* recursiveInsertion(BST* root, int key)
{
    if(!root)
        return newNode(key);
    else if(root->data > key)
        recursiveInsertion(root->left_child, key);
    else if(root->data < key)
        recursiveInsertion(root->right_child, key);
    return root;
}

void inOrderTraversal(BST *root)
{
    if(root)
    {
        inOrderTraversal(root->left_child);
        printf("%d ",root->data);
        inOrderTraversal(root->right_child);
    }
}

void main()
{
    root = iterativeInsertion(root, 50);
    iterativeInsertion(root, 30);
    iterativeInsertion(root, 20);
    iterativeInsertion(root, 40);
    iterativeInsertion(root, 70);
    iterativeInsertion(root, 60);
    iterativeInsertion(root, 80);
    inOrderTraversal(root);

    root = NULL;
    root = recursiveInsertion(root, 50);
    recursiveInsertion(root, 30);
    recursiveInsertion(root, 20);
    recursiveInsertion(root, 40);
    recursiveInsertion(root, 70);
    recursiveInsertion(root, 60);
    recursiveInsertion(root, 80);
    inOrderTraversal(root);
}
