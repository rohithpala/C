#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define size 1000

char stack[size];
int top = -1;
void push(char element){
    stack[++top] = element;
}

char pop(){
    if(top == -1) return -1;
    return stack[top--];
}

int precedence(char a){
    if(a == '^') return 3;
    else if(a == '/' || a == '*') return 2;
    else if(a == '+' || a == '-') return 1;
    return 0;
}

int main() {

    char expr[size], popped;
    int i, j = 0;
    scanf("%s", expr);
    int len = strlen(expr);
    for(i = 0 ; i < len ; i++){
        if(isalpha(expr[i]))
            printf("%c", expr[i]);
        else if(expr[i] == '(')
            push(expr[i]);
        else if(expr[i] == ')'){
            while((popped = pop()) != '(')
                printf("%c", popped);
        }
        else{
            if(top == -1)
                push(expr[i]);
            else{
                while(precedence(stack[top]) >= precedence(expr[i]))
                    printf("%c", pop());
                push(expr[i]);
            }
        }
    }
    while(top != -1){
        if((popped = pop()) != "(")
            printf("%c", popped);
    }
    return 0;
}
