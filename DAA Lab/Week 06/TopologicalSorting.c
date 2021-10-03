#include <stdio.h>
void main()
{
     int i, j, k, n, a[10][10], index[10], flag[10], count = 0;
     printf("Enter the no of vertices: ");
     scanf("%d", &n);
     printf("Enter the adjacency matrix:\n");
     for (i = 0; i < n; i++){
          for (j = 0; j < n; j++)
               scanf("%d", &a[i][j]);
     }
     for (i = 0; i < n; i++){
          index[i] = 0;
          flag[i] = 0;
     }
     for (i = 0; i < n; i++)
          for (j = 0; j < n; j++)
               index[i] = index[i] + a[j][i];
     printf("\nTopological Order: ");
     while (count < n){
          for (k = 0; k < n; k++){
               if ((index[k] == 0) && (flag[k] == 0)){
                    printf("%d ", (k + 1));
                    flag[k] = 1;
               }
               for (i = 0; i < n; i++){
                    if (a[i][k] == 1)
                         index[k]--;
               }
          }
          count++;
     }
}
