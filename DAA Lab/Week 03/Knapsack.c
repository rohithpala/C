#include<stdio.h>
#define MAX_SIZE 10

void swap(float *p, float *q)
{
    float temp = *p;
    *p = *q;
    *q = temp;
}

void sortBasedOnPbyW(float p[], float w[], int n){
    float PbyW[MAX_SIZE];
    int i, j, max = 0;
    for(i = 0 ; i < n ; i++)
        PbyW[i] = p[i]/w[i];

    for(i = 0 ; i < n ; i++){
        max = i;
        for(j = i ; j < n ; j++){
            if(PbyW[max] < PbyW[j])
                max = j;
        }
        swap(&p[i], &p[max]);
        swap(&w[i], &w[max]);
        swap(&PbyW[i], &PbyW[max]);
    }
}

void main()
{
    int i, n;
    float p[MAX_SIZE], w[MAX_SIZE], x[MAX_SIZE] = {0.0}, capacity, profit = 0.0;
    printf("Capacity of the Knapsack: ");
    scanf("%f", &capacity);
    printf("No. of Objects: ");
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++){
        printf("Object %d's [w p]: ", i+1);
        scanf("%f%f", &w[i], &p[i]);
    }
    sortBasedOnPbyW(p, w, n); // sorting based on p/w to get the optimal solution
    for(i = 0 ; i < n ; i++){
        if(w[i] > capacity) break;
        x[i] = 1.0;
        capacity -= w[i];
        profit += p[i];
    }
    if(i < n){
        x[i] = capacity/w[i];
        profit += x[i]*p[i];
    }
    printf("Profit: %f", profit);
}
