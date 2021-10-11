#include<stdio.h>

int a[100],n,i,j,pos,item,temp,toBeSearched,toBeInserted;

int size(int a[])
{
    int i,count=0;
    for(i=0;a[i]!=-1;i++){
        count++;
    }
    return count;
};


void Display(int a[])
{
    printf("Elements in the Array are:\n");
    for(i=0;i<size(a);i++)
        printf("a[%d] = %d\n",i,a[i]);
}


void AddElements(int temp[])
{
    int i,j=0;
    for(i=size(a);i<size(temp)+size(a);i++)
    {
        a[i] = temp[j];
        j++;
    }
    Display(a);
}


//Inserting
void Insert(int pos,int toBeInserted,int a[])
{
    printf("Original Elements are:\n");
    for(i=0;i<size(a);i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    j=size(a);
    while(j >= pos-1)
    {
        a[j+1] = a[j];
        j--;
    }
    a[pos-1] = toBeInserted;
    printf("Elements after Insertion are:\n");
    for(i=0;i<size(a);i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    printf("Insertion Successful\n\n");
}


//Deleting
void Delete(int pos,int a[])
{
        printf("Original Elements are:\n");
        for(i=0;i<size(a);i++)
        {
            printf("a[%d] = %d\n",i,a[i]);
        }
        while(pos-1 < size(a))
        {
            a[pos-1] = a[pos];
            pos++;
        }
        printf("Elements After Deletion:\n");
        if(size(a)==0)
            printf("Array is Empty\n");
        else
        {
            for(i=0;i<size(a);i++)
            {
                printf("a[%d] = %d\n",i,a[i]);
            }
        }
        printf("Deletion Successful\n\n");
}


//Sorting
void Sort(int a[],char sortingOrder)
{
    printf("Original Elements are:\n");
    for(i=0;i<size(a);i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    if(sortingOrder=='A' || sortingOrder=='a')
    {
        for(i=0;i<size(a);i++)
        {
            for(j=i+1;j<size(a);j++)
            {
                if(a[i]>a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    else
    {
        for(i=0;i<size(a);i++)
        {
            for(j=i+1;j<size(a);j++)
            {
                if(a[i]<a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    printf("Elements After Sorting\n");
    for(i=0;i<size(a);i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    printf("Sorted Successfully\n\n");
}


//Searching
void Search(int toBeSearched,int a[])
{
    int found = 0;
    for(i=0;i<size(a);i++)
    {
        if(toBeSearched == a[i])
        {
            found = 1;
            printf("%d found at %d\n\n",toBeSearched,i+1);
        }
    }
    if(found == 0)
        printf("%d not found\n\n",toBeSearched);
}


//Update
void Update(int a[])
{
        int no,positions[20],items[20];
        printf("Enter the number of Elements to be updated:");
        scanf("%d",&no);
        printf("Enter %d position(s) that is/are to be updated:\n",no);
        for(i=0;i<no;i++)
            scanf("%d",&positions[i]);
        printf("Enter %d element(s) to be placed at those position(s):\n",no);
        for(i=0;i<no;i++)
            scanf("%d",&items[i]);
        printf("Original Elements are:\n");
        for(i=0;i<size(a);i++)
        {
            printf("a[%d] = %d\n",i,a[i]);
        }
        for(i=0;i<no;i++)
            a[positions[i]-1] = items[i];
        printf("Elements after Updating are:\n");
        for(i=0;i<size(a);i++)
        {
            printf("a[%d] = %d\n",i,a[i]);
        }
        printf("Updated Successfully\n");
}


void main()
{
    int opt,tempSize,temp[100];
    char choice,sortingOrder;
    for(i=0;i<100;i++)
    {
        a[i]=-1;
        temp[i]=-1;
    }
    printf("Enter the Default Length of Array: ");
    scanf("%d",&n);
    printf("Enter elements of array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    size(a);
    do
    {
        printf("----------------What You Want to Do----------------\n");
        printf(" \t\t 1) Add Elements\n");
        printf(" \t\t 2) Insert Elements\n");
        printf(" \t\t 3) Delete Elements\n");
        printf(" \t\t 4) Sort the Elements\n");
        printf(" \t\t 5) Search an Element\n");
        printf(" \t\t 6) Update Elements\n");
        printf(" \t\t 7) Display the Elements\n");
        printf("Select an Option from Above: ");
        scanf("%d",&opt);

        switch(opt)
        {
            case 1: printf("Enter number of elements you want to add: ");
                    scanf("%d",&tempSize);
                    printf("Enter %d elements you want to add:",tempSize);
                    for(i=0;i<tempSize;i++)
                        scanf("%d",&temp[i]);
                    AddElements(temp);
                    break;
            case 2: Display(a);
                    printf("Enter a position where you want to insert:");
                    do
                    {
                        if(pos>size(a))
                            printf("ERROR: Out of Range. Enter a valid Number:");
                        else
                            scanf("%d",&pos);
                    }while(pos>size(a));
                    printf("Enter element to be Inserted: ");
                    scanf("%d",&toBeInserted);
                    Insert(pos,toBeInserted,a);
                    break;
            case 3: if(size(a)==0)
                        printf("No Elements in array to delete\n");
                    else
                    {
                        printf("\n");
                        Display(a);
                        printf("Enter position to be deleted: ");
                        scanf("%d",&pos);
                        Delete(pos,a);
                    }
                    break;
            case 4: if(size(a)==0)
                        printf("No Elements in array to sort\n");
                    else
                    {
                        printf("Which Order do You Prefer (Ascending[A] / Descending[D]): ");
                        scanf(" %c",&sortingOrder);
                        Sort(a,sortingOrder);
                    }
                    break;
            case 5: if(size(a)==0)
                        printf("No Elements in the Array to Search\n");
                    else
                    {
                        printf("Enter Element to be searched: ");
                        scanf("%d",&toBeSearched);
                        Search(toBeSearched,a);
                    }
                    break;
            case 6: if(size(a)==0)
                        printf("Sorry their are no Elements in Array to Update :D\n");
                    else
                    {
                        Display(a);
                        Update(a);
                    }
                    break;
            case 7: if(size(a)==0)
                        printf("Array is Empty\n");
                    else
                        Display(a);
            default: printf("Invalid Option\n");
                     break;
        }
        printf("Do You Want To Edit your Array[Y/N]: ");
        scanf(" %c",&choice);
    }while(choice=='Y' || choice=='y');
    printf("\n\n----------------Have a Nice Day :D----------------");
}
