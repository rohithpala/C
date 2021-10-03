#include<stdio.h>
#include<limits.h>
#include "P:\C\Sortings.h"
#define min(a, b) a < b ? a : b

typedef struct twoMinsOfArray{
     int m1, m2;
} twoMins;

twoMins minInArray(int fileSizes[], int end, int block[]){
     int i, minIndex, min = INT_MAX;
     twoMins m;
     for(i = 0 ; i <= end ; i++){
          if(min > fileSizes[i] && block[i] != 1){
               min = fileSizes[i];
               minIndex = i;
          }
     }
     block[minIndex] = 1;
     m.m1 = minIndex;
     int temp = minIndex;

     min = INT_MAX;
     for(i = 0 ; i <= end ; i++){
          if(min > fileSizes[i] && i != temp && block[i] != 1){
               min = fileSizes[i];
               minIndex = i;
          }
     }
     block[minIndex] = 1;
     m.m2 = minIndex;
     return m;
}

int OptimalMergePattern(int fileSizes[], int n){
     int i, start = 0, end = n-1, block[2*n - 1], noOfMerges = 0;
     for(i = 0 ; i < 2*n - 1 ; i++) block[i] = 0;
     twoMins m;
     for(i = 0 ; i < n-1 ; i++){
          m = minInArray(fileSizes, end, block);
          fileSizes[++end] = fileSizes[m.m1] + fileSizes[m.m2];
          block[m.m1] = block[m.m2] = 1;
          noOfMerges += fileSizes[end];
     }
     return noOfMerges;
}

void main()
{
     int i, n;
     printf("Enter number of files: ");
     scanf("%d", &n);
     int fileSizes[2*n - 1];
     printf("Enter File Sizes: ");
     for (i = 0; i < n; i++)
          scanf("%d", &fileSizes[i]);
     MergeSort(fileSizes, 0, n, 'f');
     printf("Minimum number of Merges Needed: %d", OptimalMergePattern(fileSizes, n));
}