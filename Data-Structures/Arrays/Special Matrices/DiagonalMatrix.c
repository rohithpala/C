#define MAX_SIZE 20

#include<stdio.h>
#include<stdlib.h>

int a[MAX_SIZE],n;
void Store(int r,int c,int temp)
{
    if(r!=c && temp!=0)
        printf("Invalid Element\n");
    if(r==c)
        a[r-1] = temp;
}

int Retrieve(int r,int c)
{
    if(r<1 || r>n || c<1 || c>n)
    {
        printf("Out Of Range\n");
        return NULL;
    }
    if(r==c)
        return a[r-1];
    return 0;
}

void main()
{
	//Storing and  Retrieving Diagonal matrix
	int i,j,temp,row,col;
	char choice;
	printf("Enter size of Matrix: ");
	scanf("%d",&n);
	printf("Enter the elements of the diagonal matrix:\n");
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
            if(Retrieve(row,col)!=NULL)
                        printf("Element at [%d,%d] is %d",row,col,Retrieve(row,col));
            printf("\nDo You Want To Retrieve Again: ");
            scanf(" %c",&choice);
        }while(choice == 'Y' || choice == 'y');
}
