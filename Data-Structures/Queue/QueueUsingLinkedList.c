#define MAX_SIZE 101

#include<stdio.h>
#include<stdlib.h>

int a[MAX_SIZE];
struct node
{
    int data;
    struct node *link;
};
struct node *front = NULL;
struct node *rear;

void Display()
{
    struct node *ptr = front;
    if(front==NULL)
        printf("Queue is Empty\n");
    else
    {
        while(ptr!=NULL)
        {
            printf("%d -> ",ptr->data);
            ptr = ptr->link;
        }
        printf("END OF QUEUE\n");
    }
}

void Enqueue(int element)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = element;
    temp->link = NULL;
    if(front == NULL)
    {
        front = rear = temp;
        front->link = NULL;
        rear->link = NULL;
    }
    else
    {
        rear->link = temp;
        rear = temp;
        rear->link = NULL;
    }
}

void Dequeue()
{
    struct node *freePTR;
    if(front == NULL)
        printf("No Elements in the Queue\n");
    else
    {
        freePTR = front;
        front = front->link;
        printf("%d is Dequeued Successfully\n",freePTR->data);
        free(freePTR);
    }
    Display();
}

void main()
{
    int i,n,data,opt;
    char cmd;
    rear = front;
    printf("Enter Size Of the Queue: ");
    scanf("%d",&n);
    printf("Enter Elements of The Queue: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        Enqueue(data);
    }
    Display();
    do
    {
        printf("1) ENQUEUE\n");
        printf("2) DEQUEUE\n");
        printf("3) DISPLAY elements of the Queue\n");
        printf("\n\nSelect An Option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("Enter Element You Want to Add: ");
                    scanf("%d",&data);
                    Enqueue(data);
                    Display();
                    break;
            case 2: Dequeue();
                    break;
            default:Display();
        }
        printf("Do You Want To Continue [Y/N]:");
        scanf(" %c",&cmd);
    }while(cmd == 'Y' || cmd == 'y');
}
