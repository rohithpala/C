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

int primesLessThanSize[MAX_SIZE/2];
void PrimeArray(){
    int i, j, k = 0;
    for(i = 2 ; i < MAX_SIZE ; i++){
        for(j = 2 ; j <= i/2 ; j++){
            if(i % j == 0){
                break;
            }
        }
        if(j > i/2){
            primesLessThanSize[k] = i;
            k++;
        }
    }
}

int h1(int key){
    return key % MAX_SIZE;
}

int h2(int key, int count){
    return primesLessThanSize[count] - (key % primesLessThanSize[count]);
}

void main()
{
    int hash_table[MAX_SIZE], i, j, key, probe, n;
    //Giving Default Values
    for(i = 0 ; i < MAX_SIZE ; i++){
        hash_table[i] = NULL;
    }
    PrimeArray();
    printf("No. of Elements: ");
    scanf("%d",&n);
    if(n > MAX_SIZE){
        printf("Overflow");
    }else{
        printf("Enter %d Elements:\n",n);
        for(i = 0 ; i < n ; i++){
            scanf("%d",&key);
            probe = h1(key);
            for(j = 1 ; hash_table[probe] ; j++){
                probe = (h1(key) + j*h2(key, j-1)) % MAX_SIZE;
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
