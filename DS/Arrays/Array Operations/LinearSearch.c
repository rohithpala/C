#include <stdio.h>
#include<stdlib.h>
void main()
{
    int x,n,*a,i,found=0;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter number to be found: ");
    scanf("%d",&x);
    a = (int *) malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
        if(x==*(a+i))
        {
            printf("%d found at position %d\n",x,i+1);
            found=1;
        }
    }
    if(found==0)
        printf("%d not found",x);
}
