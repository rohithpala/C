#include<stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int a[], int len, int reverse){ // Time Complexity: O(n^2)
    int i, j, temp;
    if(reverse == 0){ // Ascending Order
        for(i = 0; i < len-1; i++){
            for(j = 0; j < len-i-1; j++){
                if(a[j] > a[j+1]){
                    swap(&a[j], &a[j + 1]);
                }
            }
        }
    } else { // Descending Order
        for(i = 0; i < len-1; i++){
            for(j = 0; j < len-i-1; j++){
                if(a[j] < a[j+1]){
                    swap(&a[j], &a[j + 1]);
                }
            }
        }
    }
}

void main()
{
    int i, n;
    printf("Enter Size of the Array: ");
    scanf("%d",&n);
    
    int a[n];
    printf("Enter %d Elements: ", n);
    for(i = 0 ; i < n ; i++)
        scanf("%d",&a[i]);
    BubbleSort(a, n, 0);
    printf("\nSorted Array [A]: ");
    for(i = 0 ; i < n ; i++)
        printf("%d ",a[i]);
        
    BubbleSort(a, n, 1);
    printf("\nSorted Array [D]: ");
    for(i = 0 ; i < n ; i++)
        printf("%d ",a[i]);
    printf("\n");
}