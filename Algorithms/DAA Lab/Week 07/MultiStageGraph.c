#include <stdio.h>
#define n 8
#define INF 9999
int shortestDistance(int graph[n][n])
{
     int i, j, dist[n];
     dist[n - 1] = 0;
     for (i = n - 2; i >= 0; i--)
     {
          dist[i] = INF;
          for (j = i; j < n; j++)
          {
               if (graph[i][j] == INF)
                    continue;
               dist[i] = dist[i] < graph[i][j] + dist[j] ? dist[i] : graph[i][j] + dist[j];
          }
     }
     return dist[0];
}
void main()
{
     int graph[n][n] =
         {{INF, 5, 3, 8, INF, INF, INF, INF},
          {INF, INF, INF, INF, 3, 11, INF, INF},
          {INF, INF, INF, INF, 5, 7, 14, INF},
          {INF, INF, INF, INF, INF, INF, 2, INF},
          {INF, INF, INF, INF, INF, INF, INF, 15},
          {INF, INF, INF, INF, INF, INF, INF, 10},
          {INF, INF, INF, INF, INF, INF, INF, 3},
          {INF, INF, INF, INF, INF, INF, INF, INF}};
     printf("The shortest distance is: %d\n", shortestDistance(graph));
}