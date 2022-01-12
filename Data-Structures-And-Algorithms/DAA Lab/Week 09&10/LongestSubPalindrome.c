#include <stdio.h>
#include <string.h>
int i, j;
void lsp(char s1[], char s2[], int n, int dp[n+1][n+1]) {
     for (i = 0; i <= n; i++) {
          for (j = 0; j <= n; j++) {
               if (i == 0 || j == 0) dp[i][j] = 0;
               else if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
               else dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
          }
     }
     int index = dp[n][n];
     printf("Length of longest palindrome is: %d\n", index);
     char lsp[index + 1];
     lsp[index] = '\0';
     int i = n, j = n;
     while (i > 0 && j > 0) {
          if (s1[i - 1] == s2[j - 1]) {
               lsp[index - 1] = s1[i - 1];
               i--; j--;
               index--;
          }
          else if (dp[i - 1][j] > dp[i][j - 1]) i--;
          else j--;
     }
     printf("Longest Sub-Palindrome in %s is: %s", s1, lsp);
}
void main() {
     int n;
     printf("Enter length of the string: ");
     scanf("%d", &n);
     char s1[n], s2[n];
     printf("Enter the string: ");
     scanf("%s", s1);
     int j = n - 1;
     for (i = 0; i < n; i++){
          s2[i] = s1[j];
          j--;
     }
     int dp[n+1][n+1];
     lsp(s1, s2, n, dp);
}
