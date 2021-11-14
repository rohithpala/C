#include<stdio.h>
#include<stdbool.h>
#define SIZE 100

char tree[SIZE];

char parent(int child) {
    return tree[child/2];
} 

void leftChild(char data, int parent) {
    if(tree[parent] == '\0') printf("Parent doesn't exist\n");
    else tree[parent*2 + 1] = data;
}

void rightChild(char data, int parent) {
    if(tree[parent] == '\0') printf("Parent doesn't exists\n");
    else tree[parent*2 + 2] = data;
}

void displayTree() {
    int i;
    printf("Tree: ");
    for(i = 0 ; i < SIZE ; i++) {
        printf("%c ", tree[i]);
    }
    printf("\n");
}

bool isPresent(int index) {
    if(tree[index]) return true;
    return false;
}

void main() {
    int index;
    char cmd;
    tree[0] = 'A';
    leftChild('B',0);
    rightChild('C',0);
    leftChild('D',1);
    rightChild('E',1);
    leftChild('F',2);
    rightChild('G',2);
    leftChild('H',5);
    rightChild('I',5);
    displayTree();
    do {
        printf("Enter Index: ");
        scanf("%d", &index);
        if(isPresent(index)) {
            printf("%c is present at index %d\n", tree[index], index);
            printf("%c's parent is %c\n", tree[index], parent(index));
        } else {
            printf("No element present at index %d\n",index);
        }
        printf("Do You Want to check Again [Y/N]: ");
        scanf(" %c", &cmd);
    } while(cmd == 'Y' || cmd == 'y');
}
