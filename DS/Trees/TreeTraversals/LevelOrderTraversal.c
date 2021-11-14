#include <stdio.h>
#include<stdbool.h>
#define MAX_SIZE 20

typedef struct BT {
     int data;
     struct BT* left, right;
} BT;

BT* newNode(int data) {
     BT* tempNode = (BT*) malloc(sizeof(BT*));
     tempNode->data = data;
     tempNode->left = tempNode->right = NULL;
     return tempNode;
}

BT* temp;
BT* node(BT* root, int data) {
     if (!root) return NULL;
     else if (root->data == data) return root;
     else {
          if (root->left)
               return node(root->left, data);
          else if (root->right)
               return node(root->right, data);
     }
}

BT* constructTree(int tree[], int size) {
     int i;
     BT* root = newNode(tree[0]);
     for(i = 1 ; i < size ; i++) {
          temp = node(root, tree[i/2]);
          if (temp != NULL) {
               ;
          }
     }
}

void main() {
     int i, data, tree[MAX_SIZE], size = 0;
     char ch;
     FILE *fp = fopen("../tree.txt", "r");
     for (i = 0 ; fscanf(fp, "%d ", &data) == 1 ; i++) {
          tree[i] = data;
          size++;
     }
     fclose(fp);
     constructTree(tree, size);
}
