#include <stdio.h>

void swap(int *x, int *y) {
   *x = *x + *y;
   *y = *x - *y;
   *x = *x - *y;
}

void heapify(int a[], int n, int i) {
   int largest = i;
   int left = 2 * i + 1;
   int right = 2 * i + 2;

   if (left < n && a[largest] < a[left]) { // a[largest] > a[left] for descending order
      largest = left;
   }
   
   if (right < n && a[largest] < a[right]) { // a[largest] > a[right] for descending order
      largest = right;
   }

   if (largest != i) {
      swap(&a[largest], &a[i]);
      heapify(a, n, largest);
   }
}

void heapSort(int a[], int n) {
   int i;
   for (i = (n / 2) - 1; i >= 0; i--) {
      heapify(a, n, i);
   }

   // Heap Sort
   for (i = n - 1; i > 0; i--) {
      // Swap root element with last element
      swap(&a[0], &a[i]);

      // Heapify the new tree at root, to get next sorted element
      heapify(a, i, 0);
   }
}

void main()
{
   int a[] = {0, 10, 5, 12, 5, 6, 8};
   int i, n = sizeof(a) / sizeof(a[0]);
   heapSort(a, n);
   for (i = 0; i < n; i++)
      printf("%d ", a[i]);
}
