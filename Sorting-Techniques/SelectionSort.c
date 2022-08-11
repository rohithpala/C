#include<stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int a[], int n, int reverse) { // Time Coplexity: O(n^2)
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

void main()
{
    int i, n;
    printf("Enter Size of the array: ");
    scanf("%d",&n);

    int a[n];
    printf("Enter %d Elements: ", n);
    for(i = 0 ; i < n ; i++)
        scanf("%d",&a[i]);
    SelectionSort(a, n, 0);
    printf("\nSorted Array [A]: ");
    for(i = 0 ; i < n ; i++)
        printf("%d ",a[i]);
    SelectionSort(a, n, 1);
    printf("\nSorted Array [D]: ");
    for(i = 0 ; i < n ; i++)
        printf("%d ",a[i]);
    printf("\n");
}
