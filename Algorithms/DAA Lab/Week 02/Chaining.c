#include<stdio.h>
#include<stdlib.h>
# define MAX_SIZE 10

typedef struct LinkedList{
    int key;
    struct LinkedList *link;
} LL;
LL *p = NULL, *q, *hash_table[MAX_SIZE];

void insert(int* hash_table[], int n, int key){
    LL *temp = (LL*)malloc(sizeof(LL));
    temp->key = key;
    temp->link = hash_table[key % n];
    hash_table[key % n] = temp;
}

void main()
{
    int i, n, key;
    printf("Enter the Size of Hash Table: ");
    scanf("%d",&n);
    printf("Enter Elements to be Inserted into the Hash Table [Type -1 if completed]:\n");
    do{
        scanf("%d",&key);
        insert(hash_table, n, key);
    }while(key != -1);
    printf("\n");
    for(i = 0 ; i < n ; i++){
        if(hash_table[i]){
            if(i == MAX_SIZE/2)
                printf("\n");
            printf("[%d]: ", i);
            q = hash_table[i];
            while(q != NULL){
                printf("%d ", q->key);
                q = q->link;
            }
            printf("   ");
        }
    }
}
