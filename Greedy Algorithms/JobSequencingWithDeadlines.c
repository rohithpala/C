#include<stdio.h>
#include<limits.h>

void swap(int *x, int *y){
     int temp = *x;
     *y = *y;
     *y = temp;
}

void sortBasedOnProfits(int n, int jobs[], int deadlines[], int profits[]){
     int i, j;
     for(i = 0 ; i < n-1 ; i++){
          for(j = i+1 ; j < n ; j++){
               if(profits[i] < profits[j]){
                    swap(&jobs[i], &jobs[j]);
                    swap(&profits[i], &profits[j]);
                    swap(&deadlines[i], &deadlines[j]);
               }
          }
     }
}

int scheduleJobs(int n, int jobs[], int deadlines[], int profits[]){
     int i, j, maxDeadline = deadlines[0], maxProfit = 0;
     for(i = 1 ; i < n ; i++){
          if(maxDeadline < deadlines[i])
               maxDeadline = deadlines[i];
     }
     int jobsAccepted[maxDeadline];
     for(i = 0 ; i < maxDeadline ; i++) jobsAccepted[i] = -1;

     for(i = 0 ; i < n ; i++){
          for(j = deadlines[i]-1 ; j >= 0 ; j--){
               if(jobsAccepted[j] == -1){
                    jobsAccepted[j] = jobs[i];
                    maxProfit += profits[i];
                    break;
               }
          }
     }

     printf("Jobs Accepted in order are ");
     for(i = 0 ; i < maxDeadline ; i++){
          printf("J%d ", jobsAccepted[i]);
     }
     printf("\nMaximum Profit: %d", maxProfit);
}

void main()
{
     int i, n;
     printf("Enter no. of Jobs: ");
     scanf("%d", &n);
     int jobs[n], deadlines[n], profits[n];
     for(i = 0 ; i < n ; i++) jobs[i] = i+1;
     printf("Enter Deadlines: ");
     for(i = 0 ; i < n ; i++) scanf("%d", &deadlines[i]);
     printf("Enter Profits: ");
     for(i = 0 ; i < n ; i++) scanf("%d", &profits[i]);
     sortBasedOnProfits(n, jobs, deadlines, profits);
     for(i = 0 ; i < n ; i++){
          printf("%d %d %d\n", jobs[i], profits[i], deadlines[i]);
     }
     scheduleJobs(n, jobs, deadlines, profits);
}