#include<stdio.h>

char tree[100];

void leftChild(char data, int parent)
{
    if(tree[parent] == '\0')
        printf("Parent doesn't exist\n");
    else
        tree[parent*2+1] = data;
}

void rightChild(char data, int parent)
{
    if(tree[parent] == '\0')
        printf("Parent doesn't exists\n");
    else
        tree[parent*2+2] = data;
}

void displayTree()
{
    int i;
    for(i = 0 ; i < sizeof(tree)/sizeof(tree[0]) ; i++)
    {
        if(tree[i] || tree[i] != '\0')
            printf("%c ",tree[i]);
    }
}

void isPresent(int ind)
{
    if(tree[ind])
        printf("'%c' is present at %d\n", tree[ind], ind);
    else
        printf("No element present at %d\n",ind);
}

void main()
{
    int ind;
    char cmd = 'Y';
    tree[0] = 'A';
    leftChild('B',0);
    rightChild('C',0);
    leftChild('D',1);
    rightChild('E',1);
    leftChild('F',2);
    rightChild('G',2);
    leftChild('H',5);
    rightChild('I',5);
    while(cmd == 'Y' || cmd == 'y')
    {
        printf("Enter Index: ");
        scanf("%d",&ind);
        isPresent(ind);
        printf("Do You Want to check Again [Y/N]: ");
        scanf(" %c",&cmd);
    }
    displayTree();
}
