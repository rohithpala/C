#include<stdio.h>
#include<stdlib.h>
#include "P:\C\Sortings.h"

int main()
{
    int n, i, quotient, amt, temp, count = 0, *den;
    printf("No. of Denominations: ");
    scanf("%d",&n);
    den = (int*)malloc(n*sizeof(int));
    printf("Enter the Denominations: ");
    for(i = 0 ; i < n ; i++){
        scanf("%d",&den[i]);
    }
    printf("Enter Amount: ");
    scanf("%d",&amt);
    MergeSort(den, 0, n);
    temp = amt;
    for(i = n-1 ; i >= 0 ; i--){
        quotient = (int)(amt/den[i]);
        amt -= quotient*den[i];
        count += quotient;
        if(quotient != 0)
            printf("%-4d : %d\n", den[i], quotient);
        if(amt == 0)
            break;
    }
    printf("Minimum Number of Denominations: %d", count);
    printf("\nObtained Amount: %d", temp - amt);
    printf("\nRemained Amount: %d\n", amt);
    return 0;
}
