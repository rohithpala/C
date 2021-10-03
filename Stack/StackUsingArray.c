#include<stdio.h>

int top = -1;

char isEmpty(int stack[]){
     if(top == -1)
          return 't';
     return 'f';
}

char isFull(int stack[], int n){
     if(top == n-1)
          return 't';
     return 'f';
}

void push(int stack[], int element){
     stack[++top] = element;
}

int pop(int stack[]){
     return stack[top--];
}

void display(int stack[]){
     int i;
     for(i = 0 ; i <= top ; i++)
          printf("%d ", stack[i]);
}

void main()
{
     int n, element, choice, i;
     char ch;
     printf("Number of Elements: ");
     scanf("%d", &n);
     int stack[n];
     for(i = 0 ; i < n ; i++){
          scanf("%d", &element);
          push(stack, element);
     }
     do{
          printf("1) Push\n2) Pop\n 3) Display");
          scanf("%d", &choice);
          switch (choice){
          case 1:  if(isFull)
                   printf("Enter the element to be Pushed: ");
                   scanf("%d", &element);
                   push(stack, element);
                   break;
          case 2:  printf("Popped Element: %d\n", pop(stack));
          default: printf("Invalid Option");
          }
          printf("Wan to Continue[Y/N]: ");
          scanf("%c", &ch);
     }while(ch == 'Y' || ch == 'y');
}