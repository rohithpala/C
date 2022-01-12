#include <stdio.h>
int main()
{
     int i, j, n, sum;
     printf("Enter the size of Array and Sum: ");
     scanf("%d %d", &n, &sum);
     int a[n];
     for (i = 0; i < n; i++) scanf("%d", &a[i]);
     int table[n + 1][sum + 1];
     for(i = 0; i < sum + 1; i++) table[0][i] = 0;
     for(i = 0; i < n + 1; i++) table[i][0] = 1;
     for(i = 1; i < n + 1; i++){
          for(j = 1; j < sum + 1; j++){
               if (j < a[i - 1]) table[i][j] = table[i - 1][j];
               else if (table[i - 1][j] == 1 || table[i - 1][j - a[i - 1]] == 1) table[i][j] = 1;
               else table[i][j] = 0;
          }
     }
     if (table[n][sum]) printf("Subset is possible");
     else printf("Subset is not possible");
}