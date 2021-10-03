#include<stdio.h>
#include<limits.h>

void MultistageGraphProblem(int n, int stages, int cost_matrix[][n]){
     int nextVertex[n], path[stages], cost[n];
     int i, j, min;
     
     cost[n-1] = 0;
     for(i = n-2 ; i >= 0 ; i--){
          min = INT_MAX;
          for(j = i+1 ; j < n ; j++){
               if(cost_matrix[i][j] != 0 && cost_matrix[i][j] + cost[j] < min){
                    min = cost_matrix[i][j] + cost[j];
                    nextVertex[i] = j;
               }
          }
          cost[i] = min;
     }

     // Printing the Path
     path[0] = 0;
     path[stages-1] = n-1;
     for(i = 1 ; i < stages-1 ; i++) path[i] = nextVertex[path[i-1]];
     printf("\nPath: ");
     for(i = 0 ; i < stages ; i++) printf("%d ", path[i]);
     
     printf("\nShortest Distance: %d", cost[0]);
}

void main()
{
     int i, j, n;
     printf("Number of Nodes: ");
     scanf("%d", &n);
     int stages;
     printf("Number of Stages: ");
     scanf("%d", &stages);
     int cost_matrix[n][n];
     printf("Enter the Cost Matrix of Multistage Graph:\n");
     for(i = 0 ; i < n ; i++){
          for(j = 0 ; j < n ; j++){
               scanf("%d", &cost_matrix[i][j]);
          }
     }
     MultistageGraphProblem(n, stages, cost_matrix);
}
