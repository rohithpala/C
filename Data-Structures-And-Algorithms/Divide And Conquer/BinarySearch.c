#include<stdio.h>

int IterativeBinarySearch(int a[], int n, int key){
     int start = 0, end = n-1, mid;
     while(end >= start){
          mid = (start + end) / 2;
          if(key < a[mid]) end = mid - 1;
          else if(key == a[mid]) return mid;
          else start = mid + 1;
     }
     return -1;
}

int RecursiveBinarySearch(int a[], int n, int start, int end, int key){
     int mid = (start + end) / 2;
     if(key < a[mid]) return RecursiveBinarySearch(a, n, start, mid-1, key);
     else if(key == a[mid]) return mid;
     return RecursiveBinarySearch(a, n, mid+1, end, key);
}

void main()
{
     int i, n, key;
     printf("Enter no. of Elements: ");
     scanf("%d", &n);
     int a[n];
     printf("Enter the sorted Array with %d elements: ", n);
     for(i = 0 ; i < n ; i++)
          scanf("%d", &a[i]);
     printf("Enter key to be searched: ");
     scanf("%d", &key);
     printf("Key is at %d\n", IterativeBinarySearch(a, n, key));
     printf("Key is at %d", RecursiveBinarySearch(a, n, 0, n, key));
}
