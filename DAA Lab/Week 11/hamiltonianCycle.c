#include <stdio.h>
#include <stdbool.h>
#define NODE 5
int i, v;
int graph[NODE][NODE] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0},
};
int path[NODE];
void displayCycle()
{
     printf("Cycle: ");
     for (i = 0; i < NODE; i++)
          printf("%d ", path[i]);
     printf("%d\n", path[0]);
}
bool isValid(int v, int k)
{
     if (graph[path[k - 1]][v] == 0)
          return false;
     for (i = 0; i < k; i++)
          if (path[i] == v)
               return false;
     return true;
}
bool cycleFound(int k)
{
     if (k == NODE)
     {
          if (graph[path[k - 1]][path[0]] == 1)
               return true;
          else
               return false;
     }
     for (v = 1; v < NODE; v++)
     {
          if (isValid(v, k))
          {
               path[k] = v;
               if (cycleFound(k + 1) == true)
                    return true;
               path[k] = -1;
          }
     }
     return false;
}
bool hamiltonianCycle()
{
     for (i = 0; i < NODE; i++)
          path[i] = -1;
     path[0] = 0;
     if (cycleFound(1) == false)
     {
          printf("Solution does not exist\n");
          return false;
     }
     displayCycle();
     return true;
}

void main()
{
     hamiltonianCycle();
}
