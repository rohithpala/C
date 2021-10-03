#include <stdio.h>
#include <math.h>
int flag[200] = {0};
float knapSack(int W, int wt[], float val[], int n){
     int i, w, k;
     float K[n + 1][W + 1];
     for (i = 0; i <= n; i++){
          for (w = 0; w <= W; w++){
               if (i == 0 || w == 0) K[i][w] = 1.0;
               else if (wt[i - 1] <= w) K[i][w] = val[i - 1] * K[i - 1][w - wt[i - 1]];
               else K[i][w] = K[i - 1][w];
          }
     }
     i = n; k = W;
     while (i > 0 && k > 0){
          if (K[i][k] != K[i - 1][k]){
               flag[i] = 1;
               k = k - wt[i - 1];
          }
          i--;
     }
     return K[n][W];
}
int main()
{
     int i, j, k = 0, n, cost, total = 0, weight;
     printf("Number of Systems: ");
     scanf("%d", &n);
     printf("Enter cost: ");
     scanf("%d", &cost);
     int ci[n], ui[n];
     int sum = 0;
     float ri[n];
     printf("Enter cost and reliability for each system:\n");
     for (i = 0; i < n; i++){
          scanf("%d %f", &ci[i], &ri[i]);
          sum += ci[i];
     }
     for (i = 0; i < n; i++){
          ui[i] = (int)((cost + ci[i] - sum) / ci[i]);
          total += ui[i];
     }
     int t[total], wt[total];
     float val[total];
     for (i = 0; i < n; i++){
          for (j = 0; j < ui[i]; j++){
               t[k] = ((i + 1) * 10) + j + 1;
               if (j == 0){
                    val[k] = ri[i];
                    wt[k] = ci[i] * (j + 1);
                    k++;
               } else {
                    val[k] = (1 - (pow((float)(1 - ri[i]), j + 1)));
                    wt[k] = ci[i] * (j + 1);
                    k++;
               }
          }
     }
     printf("Maximum Reliabilty = %f", knapSack(cost, wt, val, total));
     printf("\nConsidered Items Are:\n");
     printf("(");
     for (i = 0; i < total; i++){
          printf("%d - %d, ", t[i], flag[i + 1]);
          if (flag[i + 1] == 1) weight += wt[i];
     }
     printf(")\n");
     printf("Weight = %d\n", weight);
     return 0;
}