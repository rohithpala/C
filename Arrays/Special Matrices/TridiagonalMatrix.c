#define MAX_SIZE 20

#include<stdio.h>
#include<stdlib.h>

int a[MAX_SIZE],n;
void Store(int r,int c,int temp)
{
    switch(r-c)
    {
        case 1: a[r-1] = temp;
                break;
        case 0: a[n+r-1] = temp;
                break;
        case -1: a[2*n+r-1] = temp;
                 break;
    }
}

int Retrieve(int r,int c)
{
    if(r<1 || r>n || c<1 || c>n)
        exit(0);
    else if(r-c == 1)
        return a[r-1];
    else if(r-c == 0)
        return a[n+r-1];
    else if(r-c == -1)
        return a[2*n+r-1];
    return 0;
}

void main()
{
	//Storing and  Retrieving Tridiagonal matrix
	int i,j,temp,row,col;
	char choice;
	printf("Enter size of Matrix: ");
	scanf("%d",&n);
	printf("Enter the elements of the tridiagonal matrix:\n");
		for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&temp);
                Store(i,j,temp);
            }
        }
        do
        {
            printf("Enter row and column to retrieve:");
            scanf("%d%d",&row,&col);
            printf("Element at [%d,%d] is %d",row,col,Retrieve(row,col));
            printf("\nDo You Want To Retrieve Again: ");
            scanf(" %c",&choice);
        }while(choice == 'Y' || choice == 'y');
}
