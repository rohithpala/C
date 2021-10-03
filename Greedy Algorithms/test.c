#include<stdio.h>
#include<math.h>
#include<string.h>
#define max pow(10, 18)

// void swap(char *i, char *j){
//      char t = *i;
//      *i = *j;
//      *j = t;
// }

void main()
{
     char t, num[5];
     int i, len;
     scanf("%s", num);
     len = strlen(num);
     for(i = len-1 ; i > 0 ; i--){
          if((int)num[i] > (int)num[i-1]){
               // swap(&num[i], &num[i-1]);
               t = num[i];
               num[i] = num[i-1];
               num[i-1] = t;
               break;
          }
     }
     if(i != 0)
          printf("%s", num);
     else
          printf("-1");
}