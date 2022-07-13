#include<stdio.h>
#include<stdlib.h> // Contains the inbuilt library sorting technique qsort

// nlogn time complexity
void* cmp(int* a, int* b){ // We encounter a warning
     // Ascending Order
     // if(*a - *b <= 0) return -1;
     // else if(*a - *b == 0) return 0;
     // return 1;

     // Descending Order
     if(*a - *b <= 0) return 1;
     else if(*a - *b == 0) return 0;
     return -1;
}

void main(){
     int a[] = {10, 15, 5, 1, 12, 2, 7, 6};
     int i, len = sizeof(a)/sizeof(a[0]);
     qsort(a, len, sizeof(a[0]), cmp); // cmp is comparator
     for(i = 0 ; i < len ; i++)
          printf("%d ", a[i]);
}
