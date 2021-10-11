#include <stdio.h>
#include <limits.h>
#define n 4
int i, j, upperBoundU = INT_MAX;
int c[n] = {0}, u[n] = {0}, v[n] = {0};
int idx = -1;
void bb(int p[n], int i){
     for (j = 0; j < n; j++)
          if (v[j] == 0)
               u[i] += p[j];
}

int l = 0;
int possible(int m, int d[n]){
     for (i = 0; i < m; i++)
          if (v[i] == 1 && d[i] == d[m])
               return 0;
     return 1;
}

void jobSequencing(int p[n], int k, int d[n]){
     for (i = k; i < n; i++){
          if (v[i] == 0){
               v[i] = 1;
               bb(p, i);
               if (u[i] < upperBoundU && possible(i, d)){
                    upperBoundU = u[i];
                    idx = i;
               }
               v[i] = 0;
               u[i] = 0;
          }
     }
     if (possible(idx, d)) v[idx] = 1;
     upperBoundU = INT_MAX;
     l++;
     if (l < n) jobSequencing(p, idx, d);
}
void main()
{
     int p[n] = {5, 10, 6, 3};
     int d[n] = {1, 2, 1, 1};
     jobSequencing(p, 0, d);
     printf("\nConsidered Jobs are: ");
     int costc = 0, costu = 0;
     for (i = idx; i >= 0; i--) if (v[i] == 0) costc += p[i];

     for (i = 0; i < n; i++){
          if (v[i] == 0)
               costu += p[i];
          printf("%d ", v[i]);
     }
     printf("\nMinimum Cost: c = %d u = %d\n", costc, costu);
}