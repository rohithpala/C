#include<stdio.h>

int main()
{
    int i, quotient, amt, count = 0;
    int den[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    printf("Enter Amount: ");
    scanf("%d",&amt);
    for(i = 8 ; i >= 0 ; i--){
        quotient = (int)(amt/den[i]);
        amt -= quotient*den[i];
        count += quotient;
        if(quotient != 0)
            printf("%-4d : %d\n", den[i], quotient);
        if(amt == 0)
            break;
    }
    printf("Minimum Number of Denominations: %d", count);
    return 0;
}
