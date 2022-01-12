#include<stdio.h>
#include<stdlib.h>

typedef struct BinaryTree {
    int data;
    struct BinaryTree *left, *right;
} BT;

int index = 0, front = -1, rear = -1, queue[10], traversal[10];
void levelOrderTraversal(root) {
     if(!root) return;
     queue[index] = root->left->data;
     queue[index++] = root->right->data;
}

void main() {
    BT *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    levelOrderTraversal(root);
}
