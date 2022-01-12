#include <stdio.h>

//O(n*log(n))

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

int getPivotIndex(int a[], int start, int end)
{
    int i = start;
    int j = end;
    int pivot = a[start];
    while (i < j)
    {
        while (a[i] <= pivot && i != end)
            i++;
        while (a[j] >= pivot && j != start)
            j--;
        if (i < j)
            swap(&a[i], &a[j]);
    }
    swap(&a[start], &a[j]);
    return j;
}

void quickSort(int a[], int start, int end)
{
    int pivotIndex;
    if (start < end)
    {
        pivotIndex = getPivotIndex(a, start, end);
        quickSort(a, start, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, end);
    }
}

void main()
{
    int n, i;
    printf("Enter Size of the array: ");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quickSort(a, 0, n - 1);
    printf("\nSorted Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
