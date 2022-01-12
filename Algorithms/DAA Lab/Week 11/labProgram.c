// LAB PROGRAMS
// Write a program to implement Subset sum problem. Subset sum problem is to find subset of elements that are
// selected from a given set whose sum adds up to a given number K. We are considering the set contains nonnegative values. It is assumed that the input set is unique (no duplicates are presented).
#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE(a) (sizeof(a)) / (sizeof(a[0]))
static int total_nodes;
int i;
void printSubset(int A[], int size){
     for(i = 0; i < size; i++) printf("%*d", 5, A[i]);
     printf("\n");
}
void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum){
     total_nodes++;
     if (target_sum == sum){
          printSubset(t, t_size);
          subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
     }else{
          for(i = ite; i < s_size; i++){
               t[t_size] = s[i];
               subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
          }
     }
}
void generateSubsets(int s[], int size, int target_sum){
     int *tuplet_vector = (int *)malloc(size * sizeof(int));
     subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
     free(tuplet_vector);
}
void main(){
     int weights[] = {10, 7, 5, 18, 12, 20, 15};
     int size = ARRAYSIZE(weights);
     generateSubsets(weights, size, 35);
     printf("Nodes generated %d \n", total_nodes);
}
