#include<stdio.h>
#define MAX_SIZE 5

void Display(int m, int n, int c[m][n])
{
    int i, j;
    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            printf("%d ",c[i][j]);
        } printf("\n");
    }
}

void main()
{
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE], m1, n1, m2, n2, i, j, k;
    printf("Number of Rows in First Matrix: ");
    scanf("%d", &m1);
    printf("Number of Columns in First Matrix: ");
    scanf("%d",&n1);
    for(i = 0 ; i < m1 ; i++){
        for(j = 0 ; j < n1 ; j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Number of Rows in Second Matrix: ");
    scanf("%d", &m2);
    printf("Number of Columns in Second Matrix: ");
    scanf("%d",&n2);
    for(i = 0 ; i < m2 ; i++){
        for(j = 0 ; j < n2 ; j++){
            scanf("%d",&b[i][j]);
        }
    }

    printf("1)Addition\n2)Subtraction\n3)Multiplication\nSelect an Option: ");
    scanf("%d",&i);
    switch(i){
        case 1:
            if(m1 != m2 && n1 != n2){
                printf("Cannot Perform Addition\n");
            } else {
                for(i = 0; i < m1 ; i++){
                    for(j = 0 ; j < n1 ; j++){
                        c[i][j] = a[i][j] + b[i][j];
                    }
                }
                Display(m1, n1, c);
            }
            break;

        case 2:
            if(m1 != m2 && n1 != n2){
                printf("Cannot Perform Subtraction\n");
            } else {
                for(i = 0; i < m1 ; i++){
                    for(j = 0 ; j < n1 ; j++){
                        c[i][j] = a[i][j] - b[i][j];
                    }
                }
                Display(m1, n1, c);
            }
            break;

        case 3:
            if(m2 != n1){
                printf("Cannot Perform Multiplication\n");
            } else {
                for(i = 0 ; i < m1 ; i < n1){
                    for(j = 0 ; j < n2 ; j++){
                        c[i][j] = 0;
                        for(k = 0 ; k < m2 /*or n1*/; k++){
                            c[i][j] += a[i][k] + b[k][j];
                        }
                    }
                }
                Display(m1, n2, c);
            }
            break;
    }
}
