#include<stdio.h>

long long int fibonacci(int n, long long int memArray[]){
     if(n == 1 || n == 2){
          memArray[n] = 1;
     } else if(memArray[n] == -1) {
          memArray[n] = fibonacci(n-1, memArray) + fibonacci(n-2, memArray);
     }
     return memArray[n];
}

void main()
{
     int n;
     printf("Enter n: ");
     scanf("%d", &n);
     int i;
     long long int memArray[n+1];
     for(i = 0 ; i < n+1 ; i++) memArray[i] = -1;
     printf("%dth Fibonacci Number is %lld", n, fibonacci(n, memArray));
}