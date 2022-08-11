#include<stdio.h>

void InsertionSort(int a[], int n, int reverse) { // Time Complexity: O(n^2)
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

void main()
{
    int i, n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    
    int a[n];
    printf("Enter %d Elements: ", n);
    for(i = 0 ; i < n ; i++)
        scanf("%d",&a[i]);
    InsertionSort(a, n, 0);
    printf("\nSorted Array [A]: ");
    for(i = 0 ; i < n ; i++)
        printf("%d ",a[i]);
    InsertionSort(a, n, 1);
    printf("\nSorted Array [D]: ");
    for(i = 0 ; i < n ; i++)
        printf("%d ",a[i]);
}
