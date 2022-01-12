#include <stdio.h>

int IterativeBinarySearch(int a[], int n, int key)
{
    int start = 0, end = n - 1, mid;
    while (end >= start)
    {
        mid = (start + end) / 2;
        if (a[mid] == key)
            return mid;
        else if (key < a[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int RecursiveBinarySearch(int a[], int start, int end, int key)
{
    if(end >= start) {
        int mid = (start + end) / 2;
        if(a[mid] == key)
            return mid;
        else if(key < a[mid])
            return RecursiveBinarySearch(a, start, mid-1, key);
        else if(key > a[mid])
            return RecursiveBinarySearch(a, mid+1, end, key);
    }
    return -1;
}

void main()
{
    int n, i, key, ret;
    printf("Enter Size of Array: ");
    scanf("%d", &n);
    int a[n], b[n];
    printf("Enter the Sorted Array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    printf("Enter Key to be Searched: ");
    scanf("%d", &key);

    // Iterative Binary Search
    printf("Result of Iterative Binary Search: ");
    ret = IterativeBinarySearch(a, n, key);
    if (ret != -1)
        printf("%d is present at position %d", key, ret + 1);
    else
        printf("%d is not present in the array\n", key);
        
    // Recursive Binary Search
    printf("\nResult of Recursive Binary Search: ");
    ret = RecursiveBinarySearch(b, 0, n-1, key);
    if(ret != -1)
        printf("%d is present at position %d", key, ret + 1);
    else
        printf("%d is not present in the array\n", key);
}
