#include<stdio.h>
#include<stdlib.h>

typedef struct BinaryTree {
    int data;
    struct BinaryTree *left, *right;
} BT;

BT* newNode(int data) {
    BT *tempNode = (BT*)malloc(sizeof(BT));
    tempNode->data = data;
    tempNode->left = tempNode->right = NULL;
    return tempNode;
}

void preOrderTraversal(BT *root) {
    if(root) {
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(BT *root) {
    if(root) {
        inOrderTraversal(root->left);
        printf("%d ",root->data);
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(BT *root) {
    if(root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ",root->data);
    }
}

void main() {
    BT *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Pre-Order Traversal:\t");
    preOrderTraversal(root);printf("\n");

    printf("In-Order Traversal:\t");
    inOrderTraversal(root);printf("\n");

    printf("Post-Order Traversal:\t");
    postOrderTraversal(root);
}
