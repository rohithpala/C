#include <stdio.h>
#define MAX 100
int store[MAX], n;
int graph[MAX][MAX];
int d[MAX], flag = 0;
int is_clique(int b)
{
     for (int i = 1; i < b; i++)
          for (int j = i + 1; j < b; j++)
               if (graph[store[i]][store[j]] == 0)
                    return 0;
     return 1;
}
void print(int s)
{
     for (int i = 1; i < s; i++)
          printf("%d ", store[i]);
     printf("\n");
}
void findCliques(int i, int l, int s)
{
     for (int j = i + 1; j <= n - (s - l); j++)
          if (d[j] >= s - 1)
          {
               store[l] = j;
               if (is_clique(l + 1))
                    if (l < s)
                         findCliques(j, l + 1, s);
                    else
                    {
                         flag = 1;
                         print(l + 1);
                    }
          }
}
int main()
{
     int size;
     printf("Enter no of nodes: ");
     scanf("%d", &n);
     printf("Enter number of edges : ");
     scanf("%d", &size);
     int edges[size][2];
     for (int i = 0; i < size; i++)
     {
          printf("Enter the vertices of edge %d: ", i);
          scanf("%d %d", &edges[i][0], &edges[i][1]);
     }
     int m;
     printf("Enter size of clique: ");
     scanf("%d", &m);
     for (int i = 0; i < size; i++)
     {
          graph[edges[i][0]][edges[i][1]] = 1;
          graph[edges[i][1]][edges[i][0]] = 1;
          d[edges[i][0]]++;
          d[edges[i][1]]++;
     }
     findCliques(0, 1, m);
     if (flag == 0)
          printf("No cliques with size %d\n", m);
}