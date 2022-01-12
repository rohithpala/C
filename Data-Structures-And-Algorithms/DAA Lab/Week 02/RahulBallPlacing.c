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
    int hash_table[MAX_SIZE], i, j, ballID, box, noOfBalls;
    for(i = 0 ; i < MAX_SIZE ; i++){
        hash_table[i] = NULL;
    }
    printf("No. of Balls: ");
    scanf("%d",&noOfBalls);
    if(noOfBalls > MAX_SIZE){
        printf("Sorry Rahul! You Cannot win the game");
    }else{
        printf("Enter %d Ball IDs from 1 to 100:\n", noOfBalls);
        for(i = 0 ; i < noOfBalls ; i++){
            scanf("%d",&ballID);
            box = ballID % noOfBalls;
            for(j = 1 ; hash_table[box] ; j++){
                box = (ballID + j) % noOfBalls;
            }
            hash_table[box] = ballID;
        }
        for(i = 0 ; i < noOfBalls ; i++){
                if(i == 5)
                    printf("\n");
                printf("Box %d: Ball %-3d ", i, hash_table[i]);
        }
        printf("\nCongo Rahul! You have won the game");
    }
}
