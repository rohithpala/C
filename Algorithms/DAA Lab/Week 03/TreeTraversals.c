#include<stdio.h>
#include<stdlib.h>
# define MAX_SIZE 11 // should be changed when the no. of nodes are changed

typedef struct BinarySearchTree{
    int data;
    struct BinarySearchTree *left_child, *right_child;
} BST;
BST *stack[MAX_SIZE], *current = NULL;

BST* newNode(int data){
    BST* tempNode = (BST*)malloc(sizeof(BST));
    tempNode->data = data;
    tempNode->left_child = tempNode->right_child = NULL;
    return tempNode;
}

BST* insert(BST* root, int data){
    if(root == NULL)
        return newNode(data);

    if(data < root->data)
        root->left_child = insert(root->left_child, data);
    else if(data > root->data)
        root->right_child = insert(root->right_child, data);
    return root;
}

void RecursivePreOrderTraversal(BST* root){
    if(root){
        printf("%d ", root->data);
        RecursivePreOrderTraversal(root->left_child);
        RecursivePreOrderTraversal(root->right_child);
    }
}

void RecursiveInOrderTraversal(BST* root){
    if(root){
        RecursiveInOrderTraversal(root->left_child);
        printf("%d ", root->data);
        RecursiveInOrderTraversal(root->right_child);
    }
}

void RecursivePostOrderTraversal(BST* root){
    if(root){
        RecursivePostOrderTraversal(root->left_child);
        RecursivePostOrderTraversal(root->right_child);
        printf("%d ", root->data);
    }
}

// stack operations
int top = -1;

void push(BST* root){
    stack[++top] = root;
}

BST* pop(){
    return stack[top--];
}

void IterativeTreeTraversal(BST* root, int num){
    if(num == 1){ // PreOrder
        push(root);
        while(top != -1){
            current = pop();
            printf("%d ", current->data);
            if(current->right_child)
                push(current->right_child);
            if(current->left_child)
                push(current->left_child);
        }
    }
    else if(num == 2){ // InOrder
        current = root;
        while(1){
            if(current != NULL){
                push(current);
                current = current->left_child;
            } else {
                if(top != -1){
                    current = pop();
                    printf("%d ", current->data);
                    current = current->right_child;
                } else {
                    break;
                }
            }
        }
    }
    else { //PostOrder
        current = root;
        do{
            while(current){
                if(current->right_child)
                    push(current->right_child);
                push(current);
                current = current->left_child;
            }
            current = pop();
            if(current->right_child && stack[top] == current->right_child){
                pop();
                push(current);
                current = current->right_child;
            } else {
                printf("%d ", current->data);
                current = NULL;
            }
        }while(top != -1);
    }
}

void main()
{
    BST* root = NULL;
    root = insert(root, 100);
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 120);
    insert(root, 110);
    insert(root, 130);
    printf("Recusive Traversals:\nPreOrderTraversal:  ");
    RecursivePreOrderTraversal(root);
    printf("\nInOrderTraversal:   ");
    RecursiveInOrderTraversal(root);
    printf("\nPostOrderTraversal: ");
    RecursivePostOrderTraversal(root);
    printf("\nIterative Treversals:\nPreOrderTraversal:  ");
    IterativeTreeTraversal(root, 1);
    printf("\nInOrderTraversal:   ");
    IterativeTreeTraversal(root, 2);
    printf("\nPostOrderTraversal: ");
    IterativeTreeTraversal(root, 3);
}
