#include<stdio.h>

typedef struct minmax{
     int min, max;
} minmax;

minmax findMinMax(int a[], int start, int end){
     minmax mm, mml, mmr;
     if(start == end) {
          mm.min = mm.max = a[start];
     } else if(end == start+1){
          mm.min = a[start] < a[end] ? a[start] : a[end];
          mm.max = a[start] > a[end] ? a[start] : a[end];
     } else {
          int mid = (start + end) / 2;
          mml = findMinMax(a, 0, mid);
          mmr = findMinMax(a, mid+1, end);

          mm.min = mml.min < mmr.min ? mml.min : mmr.min;
          mm.max = mml.max > mmr.max ? mml.max : mmr.max;
     }
     return mm;
}

void main()
{
     int i, n;
     printf("Enter no. of elements: ");
     scanf("%d", &n);
     int a[n];
     printf("Enter Array Elements: ");
     for(i = 0 ; i < n ; i++)
          scanf("%d", &a[i]);
     minmax res = findMinMax(a, 0, n-1);
     printf("Minimum: %d\nMaximum: %d", res.min, res.max);
}