#include<stdio.h>
#include<string.h>
#define MAX_SIZE 10

void push(int stack[], int *top, int element){
     stack[++(*top)] = element;
}

void pop(int stack[], int *top){
     (*top)--;
}

int peek(int stack[], int *top){
     return stack[*top];
}

void main()
{
     int i, n, element;
     char s[20];
     int stack[MAX_SIZE], minStack[MAX_SIZE], maxStack[MAX_SIZE];
     int top = -1, topMinStack = -1, topMaxStack = -1;
     printf("Number of Elements: ");
     scanf("%d", &n);
     for(i = 0 ; i < n ; i++){
          scanf("%s", s);
          if(s[0] == 'p' && s[1] == 'u'){
               scanf(" %d", &element);
               push(stack, &top, element);
               if(element <= minStack[topMinStack])
                    push(minStack, &topMinStack, element);
               if(element >= maxStack[topMaxStack])
                    push(maxStack, &topMaxStack, element);
          }
          else if(s[0] == 'p' && s[1] == 'o'){
               if(top == -1) printf("Stack Empty. Cannot Pop\n");
               else{
                    pop(stack, &top);
                    if(topMinStack != -1)
                         pop(minStack, &topMinStack);
                    if(topMaxStack != -1)
                         pop(maxStack, &topMaxStack);
               }
          }
          else if(strcmp(strlwr(s), "min") == 0){
               if(top == -1) printf("Stack is Empty\n");
               else printf("%d", minStack[topMinStack]);
          }
          else if(strcmp(strlwr(s), "max") == 0){
               if(top == -1) printf("Stack is Empty\n");
               else printf("%d", maxStack[topMaxStack]);
          }
     }
}