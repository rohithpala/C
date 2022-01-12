#include<stdio.h>
#define max(a, b) a > b ? a : b

// k is the table, it has n+1 rows, capacity+1 columns just to avoid confusion
// wt and pt have indices from 0 to n-1, so be careful while using them
// solution contains 0 and 1 that tells which object must be included and is of size n+1
void knapsack01(int n, int capacity, int wt[], int pt[]){
     int k[n+1][capacity+1]; // To number objects from 1 to n without any confusion
     int i, j;

     for(i = 0 ; i <= n ; i++){
          for(j = 0 ; j <= capacity ; j++){
               if(i == 0 || j == 0) k[i][j] = 0;
               else if(j >= wt[i-1]) k[i][j] = max(k[i-1][j], pt[i-1]+k[i-1][j-wt[i-1]]);
               else k[i][j] = k[i-1][j];
          }
     }

     int remainingProfit = k[n][capacity], solution[n+1];
     solution[0] = 0;
     for(i = n ; i > 0 ; i--){
          // Check the ith row
          for(j = 1 ; j <= capacity ; j++){
               if(k[i][j] == remainingProfit) break;
          }

          if(j <= capacity){ // if remainingProfit is present in ith row, check for (i-1)th row

               // If the remainingProfit is present in the (i-1)th row also
               // Then ith object is not included because remainingProfit is not due to ith object
               for(j = 0 ; j <= capacity ; j++){
                    if(k[i-1][j] == remainingProfit) break;
               }
               if(j > capacity){ // If remainingProfit is not present in (i-1)th row
                    // Then it is obtained because of ith object
                    solution[i] = 1;
                    remainingProfit -= pt[i-1];
               }
               else solution[i] = 0; // Else it is not obtanained due to ith object
          }
     }

     // Show Included Objects
     printf("\nIncluded Objects:\n");
     for(i = 1 ; i < n+1 ; i++)
          if(solution[i] == 1) printf("Object %d, [weight profit]: [%d %d]\n", i, wt[i-1], pt[i-1]);
     printf("Maximum Profit: %d", k[n][capacity]);
}

void main()
{
     int i, n, capacity;
     printf("Number of Objects: ");
     scanf("%d", &n);
     int wt[n], pt[n];
     printf("Enter Weights of Objects: ");
     for(i = 0 ; i < n ; i++) scanf("%d", &wt[i]);
     printf("Enter Profits of Objects: ");
     for(i = 0 ; i < n ; i++) scanf("%d", &pt[i]);
     printf("Capacity of the Knapsack: ");
     scanf("%d", &capacity);
     knapsack01(n, capacity, wt, pt);
}