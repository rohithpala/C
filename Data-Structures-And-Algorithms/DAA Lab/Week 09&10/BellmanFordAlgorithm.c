#include <stdio.h>
int BellmanFord(int G[20][20], int noOfVertices, int E, int edge[20][2]){
     int i, u, v, k, distance[20], S, flag = 1;
     for (i = 0; i < noOfVertices; i++) distance[i] = 1000;
     printf("Enter source: ");
     scanf("%d", &S);
     distance[S - 1] = 0;
     for (i = 0; i < noOfVertices - 1; i++) {
          for (k = 0; k < E; k++) {
               u = edge[k][0], v = edge[k][1];
               if (distance[u] + G[u][v] < distance[v]) distance[v] = distance[u] + G[u][v];
          }
     }
     for (k = 0; k < E; k++) {
          u = edge[k][0], v = edge[k][1];
          if (distance[u] + G[u][v] < distance[v]) flag = 0;
     }
     if (flag) for (i = 0; i < noOfVertices; i++) printf("Vertex: %d Distance: %d\n", i + 1, distance[i]);
     return flag;
}
void main()
{
     int noOfVertices, edge[20][2], G[20][20], i, j, k = 0;
     printf("Enter no. of vertices: ");
     scanf("%d", &noOfVertices);
     printf("Enter adjacency matrix form of graph:\n");
     for (i = 0; i < noOfVertices; i++)
          for (j = 0; j < noOfVertices; j++)
          {
               scanf("%d", &G[i][j]);
               if (G[i][j] != 0)
                    edge[k][0] = i, edge[k++][1] = j;
          }
     if (BellmanFord(G, noOfVertices, k, edge)) printf("No negative weight cycle\n");
     else printf("Negative weight cycle exists\n");
}