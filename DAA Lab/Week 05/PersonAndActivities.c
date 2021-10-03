#include<stdio.h>
#define MAX_SIZE 5

void swap(int *x, int *y){
     int temp = *x;
     *x = *y;
     *y = temp;
}

void main()
{
     int i, j, n, start[MAX_SIZE], finish[MAX_SIZE], /*activityNumber[MAX_SIZE],*/ canDo[MAX_SIZE];
     printf("No. of Activities: ");
     scanf("%d", &n);
     for(i = 0 ; i < n ; i++){
          printf("Enter the Start and Finish times of Activity %d: ", i+1);
          scanf("%d%d", &start[i], &finish[i]);
          // activityNumber[i] = i;
     }

     for(i = 0 ; i < n-1 ; i++){
          for(j = 0 ; j < n-i-1 ; j++){
               if(finish[j] > finish[j+1]){
                    swap(&start[j], &start[j+1]);
                    swap(&finish[j], &finish[j+1]);
                    // swap(&activityNumber[j], &activityNumber[j+1]);
               }
          }
     }

     for(i = 0 ; i < n ; i++)
          printf("Activity %d: %d %d\n", i+1, start[i], finish[i]);

     canDo[0] = 0;
     j = 1;
     for(i = 1 ; i < n ; i++){
          if(start[i] >= finish[canDo[i-1]]){
               // canDo[j] = activityNumber[i];
               canDo[j] = i;
               j++;
          }
     }
     printf("The Person Can Do Activities ");
     for(i = 0 ; i < j ; i++)
          printf("%d ", canDo[i]+1);
     printf(",In total he can do %d", j);
}
