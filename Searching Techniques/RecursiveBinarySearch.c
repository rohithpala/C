#include<stdio.h>

int RecursiveBinarySearch(int a[], int start, int end, int key)
{
    if(end >= start) {
        int mid = (start + end) / 2;
        if(a[mid] == key)
            return mid;
        else if(key < a[mid])
            return BinarySearch(a, start, mid-1, key);
        else if(key > a[mid])
            return BinarySearch(a, mid+1, end, key);
    }
    return -1;
}

void main()
{
    int n, i, key, ret;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the Sorted Array: ");
    for(i = 0 ; i < n ; i++)
        scanf("%d",&a[i]);
    printf("Enter Key to be Searched: ");
    scanf("%d", &key);
    ret = RecursiveBinarySearch(a, 0, n-1, key);
    if(ret != -1)
        printf("%d is present at position %d", key, ret+1);
    else
        printf("%d is not present in the array\n", key);
}
