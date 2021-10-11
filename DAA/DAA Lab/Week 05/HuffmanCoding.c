#include<stdio.h>
#include<string.h>

void main()
{
     int i, j, len, noOfChars = 0, temp;
     char message[30], tempChar;
     /*
        i,j = Loop Counters
        len = length of the message
        noOfChars = Number of Different Characters involved in the Message
        temp, tempChar = Variables used in Swapping
     */
     printf("Type the Message: ");
     gets(message);
     len = strlen(message);
     char character[len]; // Different Characters in Message are stored in this array
     int freq[len]; // Frequncies of character[i] are stored in freq[i]

     // Initializations
     for(i = 0 ; i < len ; i++){
          freq[i] = 0;
          character[i] = NULL;
     }

     // Storing Characters in "character[]" and calculating Frequencies
     for(i = 0 ; i < len ; i++){
          for(j = 0 ; j < len ; j++){
               if(message[i] == character[j]){
                    freq[j]++;
                    break;
               }
          }
          if(j == len){
               freq[strlen(character)] = 1;
               character[strlen(character)] = message[i];
          }
     }

     // Sorting in Descending Order based on frequencies
     for(i = 0 ; i < len-1 ; i++){
          if(!freq[i]) break;  // If it is NULL, stop iterating
          else if(freq[i]) noOfChars++; // If not NULL, increase noOfChars
          for(j = 0 ; j < len-i-1 ; j++){
               if(freq[j] < freq[j+1]){
                    // Swapping if freq[j] is less than freq[j+1] to get the descending order
                    temp = freq[j]; freq[j] = freq[j+1] ; freq[j+1] = temp;
                    tempChar = character[j]; character[j] = character[j+1]; character[j+1] = tempChar;
               }
          }
     }

     char code[noOfChars-1][noOfChars], c[noOfChars]; // code[i] stores huffman code of character[i]
     // c is used while finding the huffman code
     strcpy(code[0], "0");  // Huffman Code of 1st Character is always 0
     printf("Huffman Codes:\n%c : 0\n", character[0]);
     for(i = 1 ; i < noOfChars-1 ; i++){
          strcpy(c, "1");
          strcat(c, code[i-1]);
          strcpy(code[i], c);
          printf("%c : %s\n", character[i], c);
     }
     printf("%c : ", character[i]);
     for(i = 0 ; i < noOfChars-1 ; i++)  printf("1");
     printf("\n");

     int sum = 0;
     // "sum" contains the sum of product of "frequency of the character" and "length of its huffman code"
     for(i = 0 ; i < noOfChars-1 ; i++)
          sum += (i+1)*freq[i];
     sum += (noOfChars-1)*freq[i];
     printf("Average: %f", (float)sum/(float)len);  // Average is sum divided by length of message
}