#include <stdio.h>
#include<stdlib.h>

void main()
{
    int x,n,*a,i,mid,low=0,high;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter number to be found: ");
    scanf("%d",&x);
    high = n-1;
    a = (int *) malloc(n*sizeof(int));
    printf("Enter an ordered array or list: ");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    while(low<=high)
    {
        mid = (low+high)/2;
        if(x == *(a+mid))
        {
            printf("%d found at position %d",x,mid+1);
            break;
        }
        else if(x<*(a+mid))
        {
            high = mid-1;
        }
        else if(x>*(a+mid))
        {
            low = mid+1;
        }
    }
}
