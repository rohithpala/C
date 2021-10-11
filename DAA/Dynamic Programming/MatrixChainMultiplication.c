#include<stdio.h>
#include<limits.h>

// Both Codes give the same result

int numberOfMultiplications(int n, int dim[]){
     int i, j, k, diff, minimum, calc;
     int cost[n+1][n+1]; //, k_table[n+1][n+1];

     for(i = 1 ; i <= n ; i++) cost[i][i] = 0; //, k_table[i][i] = 0;

     for(diff = 1 ; diff < n ; diff++){
          for(i = 1 ; i < n-diff+1 ; i++){
               j = i + diff;
               minimum = INT_MAX;
               for(k = i ; k < j ; k++){
                    calc = cost[i][k]+cost[k+1][j]+(dim[i-1]*dim[k]*dim[j]);
                    if(calc < minimum){
                         minimum = calc;
                         // k_table[i][j] = k;
                    }
               }
               cost[i][j] = minimum;
          }
     }

     printf("Minimum Number of Multiplications: %d", cost[1][n]);
}

void main()
{
     int i, n;
     printf("Enter the Number of Matrices: ");
     scanf("%d", &n);
     int row[n], col[n], dim[n+1];
     printf("Enter the Size of %d Matrices in [row column] format:\n", n);
     for (i = 0 ; i < n ; i++){
          scanf("%d%d", &row[i], &col[i]);
          dim[i] = row[i];
     } dim[i] = col[i-1];

     numberOfMultiplications(n, dim);
}