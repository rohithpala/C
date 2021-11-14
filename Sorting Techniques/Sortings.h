#include<stdio.h>

void swap(int *p, int*q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

//Bubble sort
void BubbleSort(int a[], int n, int reverse) {
    int i, j;
    if(reverse == 0) { // Ascending Order
        for(i = 0; i < n-1; i++) {
            for(j = 0; j < n-i-1; j++) {
                if(a[j] > a[j+1]) {
                    swap(&a[j], &a[j+1]);
                }
            }
        }
    } else { // Descending Order
        for(i = 0; i < n-1; i++) {
            for(j = 0; j < n-i-1; j++) {
                if(a[j] < a[j+1]) {
                    swap(&a[j], &a[j+1]);
                }
            }
        }
    }
}

//Selection Sort
void SelectionSort(int a[], int n, int reverse) { //O(n^2)
    int i, j, tempIndex, swapVariable;
    if(reverse == 0) { // Ascending Order
        for(i = 0 ; i < n ; i++) {
            tempIndex = i;
            for(j = i ; j < n ; j++) {
                if(a[j] < a[tempIndex])
                    tempIndex = j;
            }
            swap(&a[i], &a[tempIndex]);
        }
    } else { // Descending Order
        for(i = 0 ; i < n ; i++) {
            tempIndex = i;
            for(j = i ; j < n ; j++) {
                if(a[j] > a[tempIndex])
                    tempIndex = j;
            }
            swap(&a[i], &a[tempIndex]);
        }
    }
}

//Insertion Sort
void InsertionSort(int a[], int n, int reverse) {
    int i, j, key;
    if(reverse == 0) { // Ascending Order
        for(i = 1 ; i < n ; i++) {
            key = a[i];
            j = i - 1;
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
    } else { // Descending Order
        for(i = 1 ; i < n ; i++) {
            key = a[i];
            j = i - 1;
            while (j >= 0 && a[j] < key) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
    }
}

// Merge Sort
void MergeArrays(int a[], int start, int mid, int end, int reverse) {
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left_sub_array[n1], right_sub_array[n2];

    for(i = 0 ; i < n1 ; i++)
        left_sub_array[i] = a[start + i];

    for(j = 0 ; j < n2 ; j++)
        right_sub_array[j] = a[mid + j + 1];

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

// Quick sort
int getPivotIndex(int a[], int start, int end) {
    int i = start;
    int j = end;
    int pivot = a[start];
    while(i < j) {
        while(a[i] <= pivot && i != end)
            i++;
        while(a[j] >= pivot && j != start)
            j--;
        if(i < j)
            swap(&a[i], &a[j]);
    }
    swap(&a[start], &a[j]);
    return j;
}

void quickSort(int a[], int start, int end) {
    int pivotIndex;
    if(start < end) {
        pivotIndex = getPivotIndex(a, start, end);
        quickSort(a, start, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, end);
    }
}
