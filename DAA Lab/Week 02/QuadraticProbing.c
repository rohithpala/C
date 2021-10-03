#include<stdio.h>
#define MAX_SIZE 10

int isFull(int hash_table[])
{
    int i;
    for(i = 0 ; i < MAX_SIZE ; i++){
        if(!hash_table[i])  //If NULL return 0 i;e table is not full
            return 0;
    }
    return 1;
}

void main()
{
    int hash_table[MAX_SIZE], i, j, key, probe, n;
    for(i = 0 ; i < MAX_SIZE ; i++){
        hash_table[i] = NULL;
    }
    printf("No. of Elements: ");
    scanf("%d",&n);
    if(n > MAX_SIZE){
        printf("Overflow");
    }else{
        printf("Enter %d Elements:\n",n);
        for(i = 0 ; i < n ; i++){
            scanf("%d",&key);
            probe = key % MAX_SIZE;
            for(j = 1 ; hash_table[probe] ; j++){
                probe = (key + j * j) % MAX_SIZE;
            }
            hash_table[probe] = key;
        }
        for(i = 0 ; i < MAX_SIZE ; i++){
            if(!hash_table[i])
                printf("[%d]: NULL ", i);
            else
                printf("[%d]: %-4d ", i, hash_table[i]);
            if(i == MAX_SIZE/2 - 1)
                printf("\n");
        }
    }
}
