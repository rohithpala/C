#define MAX_SIZE 101

#include<stdio.h>
#include<stdlib.h>

int a[MAX_SIZE],front=-1,rear=-1;

void Display()
{
    int i;
    if(front == -1 && rear == -1)
        printf("Queue is Empty\n");
    else
    {
        printf("Elements in the Queue:\n");
        for(i=front;i<=rear;i++)
            printf("%d ",a[i]);
    }
    printf("\n");
}

void Enqueue(int data)
{
    if(front == -1 && rear == -1)
    {
        front+=1;
        rear+=1;
        a[rear] = data;
    }
    else
    {
        rear+=1;
        a[rear] = data;
    }
}

void Dequeue()
{
    int x;
    if(front == -1 && rear == -1)
        printf("Queue is Empty");
    else if(front == rear)
    {
        x = a[front];
        front = rear = -1;
        printf("%d is Deleted Successfully and Queue is Empty\n",x);
    }
    else
    {
        x = a[front];
        front++;
        Display();
        printf("%d is Deleted Successfully\n",x);
    }
}

void main()
{
    int i,n,data,opt;
    char cmd;
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
            case 1: if(rear == MAX_SIZE-1)
                        printf("Queue is Full, Can't Perform Enqueue Operation\n");
                    else
                    {
                        printf("Enter Element You Want to Add: ");
                        scanf("%d",&data);
                        Enqueue(data);
                    }
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
