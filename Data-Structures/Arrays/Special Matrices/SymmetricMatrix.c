#define MAX_SIZE 20

#include<stdio.h>
#include<stdlib.h>

int a[MAX_SIZE],size=0,n;

int sigma(int x)
{
    int i,sum =0;
    for(i=1;i<x;i++)
        sum+= i;
    return sum;
}
void Store(int r,int c,int temp)
{
    if(r>=c)
        a[size++] = temp;
}

int Retrieve(int r,int c)
{
    if(r<1 || r>n || c<1 || c>n)
    {
        printf("Out Of Range\n");
        return NULL;
    }
    else if(r>=c)
        return a[sigma(r)+c-1];
    else if(r<c)
        return a[sigma(c)+r-1];
}

void main()
{
	//Storing and  Retrieving Symmetric matrix
	int i,j,temp,row,col;
	char choice;
	printf("Enter size of Matrix: ");
	scanf("%d",&n);
	printf("Enter the elements of the symmetric matrix:\n");
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
            printf("Enter row and column to search:");
            scanf("%d%d",&row,&col);
            if(Retrieve(row,col)!=NULL)
                printf("Element at [%d,%d] is %d",row,col,Retrieve(row,col));
            printf("\nDo You Want To Retrieve Again: ");
            scanf(" %c",&choice);
        }while(choice == 'Y' || choice == 'y');
}
