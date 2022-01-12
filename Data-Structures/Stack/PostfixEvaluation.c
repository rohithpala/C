#include<stdio.h>
#include<string.h>
#include<ctype.h>

int stack[10], top = -1;
void push(int element){
     stack[++top] = element;
}

int pop(){
     return stack[top--];
}

void main()
{
     char str[15];
     int i, len, input, first, second, popped;
     printf("Enter the Postfix Expression: ");
     scanf("%s", str);
     len = strlen(str);
     for (i = 0 ; i < len ; i++){
          if(isalpha(str[i])){
               printf("%c: ", str[i]);
               scanf("%d", &input);
               push(input);
          }
          else{
               second = pop();
               first = pop();
               switch(str[i]){
                    case '+': push(first + second);
                              break;
                    case '-': push(first - second);
                              break;
                    case '*': push(first * second);
                              break;
                    case '/': push(first / second);
                              break;
               }
          }
     }
     printf("Answer: %d", pop());
}