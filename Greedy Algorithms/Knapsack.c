#include<stdio.h>

void swap(float *p, float *q)
{
    float temp = *p;
    *p = *q;
    *q = temp;
}

void sortBasedOnPbyW(float p[], float w[], int n){
    float PbyW[n];
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
    float capacity, profit = 0.0;
    printf("Capacity of the Knapsack: ");
    scanf("%f", &capacity);
    printf("No. of Objects: ");
    scanf("%d", &n);
    float p[n], w[n], x[n];
    printf("Enter Weights of Objects: ");
    for(i = 0 ; i < n ; i++){
        scanf("%f", &w[i]);
        x[i] = 0.0;
    }
    printf("Enter Profits of Objects: ");
    for(i = 0 ; i < n ; i++)
        scanf("%f", &p[i]);
    sortBasedOnPbyW(p, w, n); // sorting based on p/w to get the optimal solution
    
    // Knapsack Code
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
