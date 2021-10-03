#include<stdio.h>
#include<math.h>
#define max(x, y) x > y ? x : y

void swap(int *m, int *n){
     *m = *m + *n;
     *n = *m - *n;
     *m = *m - *n;
}

void Heapify(int a[], int n, int level){ // Max Heap
     int i, j, parent;
     int start = (int)pow(2, level) - 1;
     int end = n;
     while(start > 0){
          for(i = start ; i <= end ; i += 2){
               parent = (i-1)/2;
               if(i != n-1){
                    if(a[i] >= a[i+1] && a[i] > a[parent]){
                         swap(&a[i], &a[parent]);
                    } else if(a[i+1] > a[i] && a[i+1] > a[parent]) {
                         swap(&a[i+1], &a[parent]);
                    }
               } else if(a[i] > a[parent]) {
                    swap(&a[i], &a[parent]);
               }
          }
          end = start - 1;
          start = (int)pow(2, level-1) - 1;
     }
     // while(k > 1){
     //      // Take Levels instead of k/2
     //      if(k % 2 == 0){
     //           cond = k-1;
     //      } else { // TODO
     //           cond = k;
     //      }
     //      for(i = k/2 ; i < cond ; i += 2){
     //           if(a[i] >= a[i+1] && a[i] > a[(i-1)/2]){
     //                swap(&a[i], &a[(i-1)/2]);
     //           } else if(a[i+1] > a[i] && a[i+1] > a[(i-1)/2]) {
     //                swap(&a[i+1], &a[(i-1)/2]);
     //           }
     //      }
     //      if(k % 2 == 0 && a[i] > a[(i-1)/2]){
     //           swap(&a[i], &a[(i-1)/2]);
     //      }
     //      k /= 2;
     // }
     swap(&a[0], &a[n-1]);
     for(i = 0 ; i < n ; i++){
          printf("%d ", a[i]);
     }
     printf("\n");
}

void HeapSort(int a[], int n){ // Fails for tree with only 5 elments
     int i;
     for(i = 1  ; i < n-1 ; i++){
          Heapify(a, n-i, (int)ceil(log2(n-i)));
     }
}

void main()
{
     int i, n;
     printf("Enter size of the array: ");
     scanf("%d", &n);
     int a[n];
     for (i = 0; i < n; i++)
          scanf("%d", &a[i]);
     printf("\nUnsorted Array: ");
     for (i = 0; i < n; i++)
          printf("%d ", a[i]);
     HeapSort(a, n);
     printf("\nSorted Array: ");
     for (i = 0; i < n; i++)
          printf("%d ", a[i]);
}