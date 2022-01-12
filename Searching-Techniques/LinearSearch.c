#include <stdio.h>

int linearSearch(int a[], int n, int key) {
     int i;
     for (i = 0; i < n; i++) {
          if (a[i] == key)
               return i;
     }
     return -1;
}

void main() {
     int n, i, key, ret;
     printf("Enter Size of Array: ");
     scanf("%d", &n);
     int a[n];
     printf("Enter the Array: ");
     for (i = 0; i < n; i++)
          scanf("%d", &a[i]);
     printf("Enter Key to be Searched: ");
     scanf("%d", &key);

     ret = linearSearch(a, n, key);
     if (ret != -1)
          printf("%d is present at position %d", key, ret + 1);
     else
          printf("%d is not present in the array", key);
}