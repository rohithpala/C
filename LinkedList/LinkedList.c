#include<stdio.h>
#include<stdlib.h>

//Free the Memory allocated dynamically before running

struct node
{
    int data;
    struct node *link;
};
int i,j;

struct node *p = NULL;

int length(struct node *p)
{
    if(p == NULL)
        return 0;
    else
    {
        struct node *q = p;
        for(i=1;q->link!=NULL;i++)
            q = q->link;
        return i;
    }
}

void Display()
{
    if(p == NULL)
        printf("The List Is Empty\n");
    else
    {
        struct node *q=p;
        while(q!=NULL)
        {
            printf("%d -> ",q->data);
            q = q->link;
        }
        printf("END OF LIST\n");
    }
}

void insertAtBeginning(int element)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = element;
    if(p == NULL)
    {
        temp->link = NULL;
        p = temp;
    }
    else
    {
        temp->link = p;
        p=temp;
    }
    Display();
    printf("Inserted Successfully\n");
}

void insertAtPosition(int pos,int element)
{
    struct node *q = p;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = element;
    for(i=1;i<pos-1;i++)
        q = q->link;
    temp->link = q->link;
    q->link = temp;
    Display();
    printf("Inserted Successfully\n");
}

void insertAtEnd(int element)
{
    struct node *q = p;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = element;
    if(p==NULL)
    {
        temp->link = NULL;
        p = temp;
    }
    else
    {
        for(i=1;q->link!=NULL;i++)
            q = q->link;
        q->link = temp;
        temp->link = NULL;
    }
    Display();
    printf("Inserted Successfully\n");
}

void deleteAtBeginning()
{
    int x;
    if(p==NULL)
        printf("No Elements to Delete\n");
    else
    {
        printf("List Before Deleting:\n");
        Display();
        x = p->data;
        p = p->link;
        printf("List After Deleting:\n");
        Display();
        printf("%d Deleted Successfully\n",x);
    }
}

void deleteAtPosition(int pos)
{
    int x;
    if(p==NULL)
        printf("No Elements to Delete\n");
    else
    {
        printf("List Before Deleting:\n");
        Display();
        struct node *q = p;
        for(i=1;i<pos-1;i++)
        {
            q = q->link;
            if(q==NULL)
                printf("Position Out Of Range\n");
        }
        x = q->data;
        q->link = q->link->link;
        printf("List After Deleting:\n");
        Display();
        printf("%d Deleted Successfully\n",x);
    }
}

void deleteAtEnd()
{
    int x;
    if(p==NULL)
        printf("No Elements to Delete\n");
    else
    {
        printf("List Before Deleting:\n");
        Display();
        if(length(p)==1)
        {
            p = NULL;
            printf("List After Deleting Is Empty\n");
        }
        else
        {
            struct node *q = p;
            while(q->link->link!=NULL)
                q = q->link;
            x = q->link->data;
            q->link=NULL;
            printf("List After Deleting:\n");
            Display();
            printf("%d Deleted Successfully\n",x);
        }
    }
}

void Reverse()
{
    struct node *q = p;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *res = NULL;
    while(q!=NULL)
    {
        temp->data = q->data;
        if(res == NULL)
        {
            temp->link = NULL;
            res = temp;
        }
        else
        {
            temp->link = res;
            res=temp;
        }
        q = q->link;
    }
    q=res;
    while(q!=NULL)
    {
        printf("%d -> ",q->data);
        q = q->link;
    }
    printf("END OF LIST\n");
}

void Sort(char choice)
{
    int temp1;
    printf("List Before Sorting:\n");
    Display();
    struct node *q = p;
    struct node *r = p;
    if(choice == 'A' || choice == 'a')
    {
        while(q->link!=NULL)
        {
            r=p;
            while(r->link!=NULL)
            {
                if (r->data>r->link->data )
                {
                    temp1 = r->link->data;
                    r->link->data = r->data;
                    r->data = temp1;
                }
                r = r->link;
            }
            q=q->link;
        }
        printf("The List After Sorting in Ascending Order is:\n");
        Display();
    }
    if(choice == 'D' || choice == 'd')
    {
        while(q->link!=NULL)
        {
            r=p;
            while(r->link!=NULL)
            {
                if (r->data < r->link->data )
                {
                    temp1 = r->link->data;
                    r->link->data = r->data;
                    r->data = temp1;
                }
                r = r->link;
            }
            q=q->link;
        }
        printf("The List After Sorting in Ascending Order is:\n");
        Display();
    }
}


void main()
{
    int opt,element,pos;
    char choice;
    do
    {
       printf("\t\tOPERATIONS THAT CAN BE PERFORMED\n___________________________________________________________________\n1)Insert At Beginning     2)Insert In Between     3)Insert At End\n4)Deletion At Beginning   5)Deletion In Between   6)Deletion At End\n");
        printf("7)Length of List          8)Reverse      9)Sort   10)Display\n___________________________________________________________________\n\nSELECT AN OPTION: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("Enter The Element You Want To Insert At The Beginning: ");
                    scanf("%d",&element);
                    insertAtBeginning(element);
                    break;
            case 2: if(p == NULL)
                    {
                        printf("The List Is Empty........So Can Enter Element Directly\n");
                        printf("Enter The Element You Want To Insert At Position %d: ",1);
                        scanf("%d",&element);
                        insertAtBeginning(element);
                    }
                    else
                    {
                        Display();
                        printf("Enter The Position: ");
                        scanf("%d",&pos);
                        if(pos>length(p))
                            printf("Position Out Of Range\n");
                        else
                        {
                            printf("Enter The Element You Want To Insert At Position %d: ",pos);
                            scanf("%d",&element);
                            insertAtPosition(pos,element);
                        }
                    }
                    break;
            case 3: printf("Enter The Element You Want To Insert At The End: ");
                    scanf("%d",&element);
                    insertAtEnd(element);
                    break;
            case 4: deleteAtBeginning();
                    break;
            case 5: Display();
                    printf("Enter the Position of Element You Want to Delete: ");
                    scanf("%d",&pos);
                    if(pos>length(p))
                        printf("Position Out Of Range\n");
                    else
                        deleteAtPosition(pos);
                    break;
            case 6: deleteAtEnd();
                    break;
            case 7: printf("Length Of List = %d\n",length(p));
                    break;
            case 8: Reverse();
                    break;
            case 9: printf("Enter Order or Preference {Ascending[A] / Descending[D]}: ");
                    scanf(" %c",&choice);
                    Sort(choice);
                    break;
            case 10:Display();
                    break;
            default:printf("Invalid Option\n");
        }
        printf("Do You Want to Change The List [Y/N]: ");
        scanf(" %c",&choice);
    }while(choice == 'Y' || choice == 'y');
}
