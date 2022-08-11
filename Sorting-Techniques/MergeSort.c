#include<stdio.h>

void MergeArrays(int a[], int start, int mid, int end, int reverse) {
     int i, j, k;
     int n1 = mid - start + 1;
     int n2 = end - mid;
     int left_sub_array[n1], right_sub_array[n2];

     for(i = 0 ; i < n1 ; i++) {
          left_sub_array[i] = a[start + i];
     }

     for(j = 0 ; j < n2 ; j++) {
          right_sub_array[j] = a[mid + j + 1];
     }

     i = j = 0;
     k = start;
     if(reverse == 0) { // Ascending Order
          while(i < n1 && j < n2) {
               if(left_sub_array[i] <= right_sub_array[j]) {
                    a[k] = left_sub_array[i];
                    i++;
               } else {
                    a[k] = right_sub_array[j];
                    j++;
               }
               k++;
          }
     } else { // Descending Order
          while(i < n1 && j < n2) {
               if(left_sub_array[i] >= right_sub_array[j]) {
                    a[k] = left_sub_array[i];
                    i++;
               } else {
                    a[k] = right_sub_array[j];
                    j++;
               }
               k++;
          }
     }

     // Append elements of left_sub_array if any
     while(i < n1) {
          a[k] = left_sub_array[i];
          i++;
          k++;
     }

     // Append elements of right_sub_array if any
     while(j < n2) {
          a[k] = right_sub_array[j];
          j++;
          k++;
     }
}

void MergeSort(int a[], int start, int end, int reverse) {
     if(start < end) {
          int mid = (start + end)/2;
          MergeSort(a, start, mid, reverse);
          MergeSort(a, mid+1, end, reverse);
          MergeArrays(a, start, mid, end, reverse);
     }
}

void main()
{
     int i, n;
     printf("Enter Size of the Array: ");
     scanf("%d", &n);
     int a[n];
     for(i = 0 ; i  < n ; i++)
          scanf("%d", &a[i]);
     MergeSort(a, 0, n-1, 0);
     printf("Sorted Array (Asc.): ");
     for(i = 0 ; i < n ; i++)
          printf("%d ", a[i]);
     MergeSort(a, 0, n-1, 1);
     printf("\nSorted Array (Des.): ");
     for(i = 0 ; i < n ; i++)
          printf("%d ", a[i]);
}
