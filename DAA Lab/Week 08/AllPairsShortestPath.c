#include<stdio.h>
#define min(a, b) a < b ? a : b

void floyds(int n, int adj_mat[][n]){
     int i, j, k;
     for (k = 0; k < n; k++){
          for (i = 0; i < n; i++){
               for (j = 0; j < n; j++){
                    if (i == j)
                         adj_mat[i][j] = 0;
                    else
                         adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
               }
          }
     }
}

void main()
{
     int wt, n, ed, v1, v2, i, j;
     printf("Enter the number of vertices an edges: ");
     scanf("%d%d", &n, &ed);
     int adj_mat[n][n];
     
     for (i = 0; i < n; i++){
          for (j = 0; j < n; j++)
               adj_mat[i][j] = 999;
     }

     printf("Enter the Edges:\n");
     for (i = 0; i < ed; i++){
          // printf("Enter the end vertices of edge %d with its weight \n", i);
          scanf("%d%d%d", &v1, &v2, &wt);
          adj_mat[v1][v2] = wt;
     }

     printf("\nAdjacency Matrix:\n");
     for (i = 0; i < n; i++){
          for (j = 0; j < n; j++)
               printf("%d\t", adj_mat[i][j]);
     }

     floyds(n, adj_mat);

     printf("\nThe Shortest Paths are:\n");
     for (i = 0; i < n; i++){
          for (j = 0; j < n; j++){
               if (i != j)
                    printf("[%d,%d] = %d\t", i, j, adj_mat[i][j]);
          }
          printf("\n");
     }
}