#include <stdio.h>
#define max(a,b) (a > b) ? a : b

int knapsack(int m, int weight[], int profit[], int n){
     int i, w;
     int K[n + 1][m + 1];
     for (i = 0; i <= n; i++){
          for (w = 0; w <= m; w++){
               if (i == 0 || w == 0) K[i][w] = 0;
               else if (weight[i - 1] <= w) K[i][w] = max(profit[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
               else K[i][w] = K[i - 1][w];
          }
     }
     return K[n][m];
}
void main()
{
     int i, n, m;
     printf("Enter n:");
     scanf("%d", &n);
     int profit[n], weight[n];
     for (i = 0; i < n; i++)
     {
          printf("Enter profit and weight of object %d: ", i + 1);
          scanf("%d %d", &profit[i], &weight[i]);
     }
     printf("Enter Capacity: ");
     scanf("%d", &m);
     printf("Maximum Profit: %d", knapsack(m, weight, profit, n));
}