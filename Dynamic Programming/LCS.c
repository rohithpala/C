#include<stdio.h>
#include<string.h>
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

void LCS(char *str1, char *str2){
     int i, j, len1, len2;
     int l1 = strlen(str1), l2 = strlen(str2);
     char *s;
     if(l1 > l2){
          len2 = l1;
          len1 = l2;
          strcpy(s, str1);
     } else {
          len1 = l1;
          len2 = l2;
          strcpy(s, str2);
     }
     int lcs_table[len1 + 1][len2 + 1], diagonal[len2 + 1];

     for(i = 1 ; i <= len1 ; i++) lcs_table[i][0] = 0;
     for(i = 1 ; i <= len2 ; i++) lcs_table[0][i] = 0;

     for(i = 1 ; i <= len1 ; i++){
          for(j = 1 ; j <= len2 ; j++){
               if(str1[i] == str2[j]) {
                    lcs_table[i][j] = 1 + lcs_table[i-1][j-1];
               } else {
                    lcs_table[i][j] = max(lcs_table[i-1][j], lcs_table[i][j-1]);
                    diagonal[j] = 1;
               }
          }
     }

     printf("\nLogest Common Subsequence is: ");
     for(i = 1 ; i <= len2 ; i++){
          if(diagonal[i] == 1) printf("%c",s[i]);
     }
}

void main()
{
     char *str1, *str2;
     printf("Enter 1st String: ");
     gets(str1);
     printf("Enter 2nd String: ");
     scanf("%s", str2);
     LCS(str1, str2);
}