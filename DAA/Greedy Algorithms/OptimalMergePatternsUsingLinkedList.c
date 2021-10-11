#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct tree{
     int data;
     struct tree *left_child, *right_child;
} tree;
tree *t = NULL;

int minInArray(int fileSizes[], int start, int end){
     int i, minIndex, min = INT_MAX;
     for(i = start ; i <= end ; i++){
          if(min > fileSizes[i]){
               min = fileSizes[i];
               minIndex = i;
          }
     }
     return minIndex;
}

tree* newNode(int data, tree* left, tree* right){
     tree* temp = (tree*)malloc(sizeof(tree));
     temp->data = data;
     temp->left_child = temp->right_child = NULL;
     return temp;
}

void OptimalMergePattern(int fileSizes[], int n){
     int i, j = 0, min1, min2;
     tree* node[n-1];
     tree* node[0] = newNode(fileSizes[0] + fileSizes[1],
                         newNode(fileSizes[0], NULL, NULL),
                         newNode(fileSizes[1], NULL, NULL));
     for(i = 2 ; i < n ; i++){
          if(node[j]->data > fileSizes[i] && node[j]->data > fileSizes[i+1]){
               node[j+1] = newNode(fileSizes[0] + fileSizes[1],
                                   newNode(fileSizes[0], NULL, NULL),
                                   newNode(fileSizes[1], NULL, NULL));
          } else if(node[j]->data > fileSizes[i] && node[j]->data > fileSizes[i+1]){
               node[j+1] = newNode(fileSizes[0] + fileSizes[1],
                                   newNode(fileSizes[0], NULL, NULL),
                                   newNode(fileSizes[1], NULL, NULL));
          }
          j++;
     }
}

void main()
{
     int i, n;
     printf("Enter number of files: ");
     scanf("%d", &n);
     int fileSizes[n];
     printf("Enter File Sizes: ");
     for (i = 0; i < n; i++)
          scanf("%d", &fileSizes[i]);
     MergeSort(fileSizes, 0, n, 'f');
     OptimalMergePattern(fileSizes, n);
}