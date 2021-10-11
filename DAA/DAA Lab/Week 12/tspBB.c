#include <stdio.h>
#include <limits.h>
#include <string.h>
#define INF 9999
#define N 5
int Matrix2[N][N], Matrix1[N][N][N], list[N + 1], visited[N] = {0};
int reducedMatrix[N][N];
int col[N], row[N];
int r = 0;
int total = 0;
int rowReduction()
{
     memset(row, INF, sizeof(row));
     for (int i = 0; i < N; i++)
          for (int j = 0; j < N; j++)
               if (reducedMatrix[i][j] < row[i])
                    row[i] = reducedMatrix[i][j];
     for (int i = 0; i < N; i++)
          for (int j = 0; j < N; j++)
               if (reducedMatrix[i][j] != INF && row[i] != INF)
                    reducedMatrix[i][j] -= row[i];
}
int columnReduction()
{
     memset(col, INF, sizeof(col));
     for (int i = 0; i < N; i++)
          for (int j = 0; j < N; j++)
               if (reducedMatrix[i][j] < col[j])
                    col[j] = reducedMatrix[i][j];
     for (int i = 0; i < N; i++)
          for (int j = 0; j < N; j++)
               if (reducedMatrix[i][j] != INF && col[j] != INF)
                    reducedMatrix[i][j] -= col[j];
}
int calculateCost()
{
     int cost = 0;
     rowReduction(reducedMatrix, row);
     columnReduction(reducedMatrix, col);
     for (int i = 0; i < N; i++)
     {
          cost += (row[i] != INF) ? row[i] : 0,
              cost += (col[i] != INF) ? col[i] : 0;
     }
     return cost;
}
void printPath()
{
     for (int i = 0; i < N; i++)
     {
          total += Matrix2[list[i]][list[i + 1]];
          printf("%d --> %d\n", list[i], list[i + 1]);
     }
}
int c = INF;
int idx, k = 0, p = 0;
int solve(int s, int costMatrix[N][N])
{
     list[k] = s;
     k++;
     visited[s] = 1;
     for (int i = 0; i < N; i++)
     {
          if (visited[i] != 1)
          {
               for (int i1 = 0; i1 < N; i1++)
                    for (int j1 = 0; j1 < N; j1++)
                         reducedMatrix[i1][j1] = Matrix1[s][i1][j1];
               for (int i2 = 0; i2 < N; i2++)
                    reducedMatrix[s][i2] = INF;
               for (int j = 0; j < N; j++)
                    reducedMatrix[j][i] = INF;
               reducedMatrix[i][0] = INF;
               int c1 = p + costMatrix[s][i] + calculateCost();
               if (c1 < c)
               {
                    c = c1;
                    idx = i;
               }
               for (int a = 0; a < N; a++)
                    for (int b = 0; b < N; b++)
                         Matrix1[i][a][b] = reducedMatrix[a][b];
          }
     }
     p = c;
     c = INF;
     if (k < N)
          solve(idx, Matrix1[idx]);
}
int main()
{
     int costMatrix[N][N] =
         {
             {INF, 20, 30, 10, 11},
             {15, INF, 16, 4, 2},
             {3, 5, INF, 2, 4},
             {19, 6, 18, INF, 3},
             {16, 4, 7, 16, INF}};
     for (int i = 0; i < N; i++)
          for (int j = 0; j < N; j++)
               Matrix2[i][j] = costMatrix[i][j];
     memset(row, INF, sizeof(row));
     for (int i = 0; i < N; i++)
          for (int j = 0; j < N; j++)
               if (costMatrix[i][j] < row[i])
                    row[i] = costMatrix[i][j];
     for (int i = 0; i < N; i++)
          for (int j = 0; j < N; j++)
               if (costMatrix[i][j] != INF && row[i] != INF)
                    costMatrix[i][j] -= row[i];
     memset(col, INF, sizeof(col));
     for (int i = 0; i < N; i++)
          for (int j = 0; j < N; j++)
               if (costMatrix[i][j] < col[j])
                    col[j] = costMatrix[i][j];
     for (int i = 0; i < N; i++)
          for (int j = 0; j < N; j++)
               if (costMatrix[i][j] != INF && col[j] != INF)
                    costMatrix[i][j] -= col[j];
     int cost = 0;
     for (int i = 0; i < N; i++)
     {
          cost += (row[i] != INF) ? row[i] : 0,
              cost += (col[i] != INF) ? col[i] : 0;
     }
     r = cost;
     p = r;
     for (int i = 0; i < N; i++)
          for (int j = 0; j < N; j++)
               Matrix1[0][i][j] = costMatrix[i][j];
     solve(0, costMatrix);
     list[5] = 0;
     printf("Path:\n");
     printPath();
     printf("Total cost is %d\n", total);
     return 0;
}