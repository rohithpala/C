/* Refer https://onlinecourses.nptel.ac.in/noc21_cs22/progassignment?name=118 for Question*/

#include<stdio.h>

void main()
{
    int n, i, j, tempIndex = 0, k = 0;
    scanf("%d",&n);
    int a[n][3], sorted[n][3];
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < 2 ; j++){
            scanf("%d",&a[i][j]);
        }
    }
    // Sorting Vocals in Ascending order : Sorting is Wrong. Check it
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
        {
            if(a[j][0] < a[i][0] && tempIndex != j)
                tempIndex =
        }
        sorted[k][0] = a[tempIndex][0];
        sorted[k][1] = a[tempIndex][1];
        k++;
    }

    for(i = 0 ; i < n ; i++){
        sorted[i][3] = (n-i-1)*2;
    }

    for(i = 0 ; i < n; i++){
        for(j = 0 ; j < n; j++){
            if(sorted[i][0] == a[j][0]){
                a[j][3] = sorted[i][3];
                break;
            }
        }
    }

    for(i = 0 ; i < n; i++){
            printf("%d ", a[i][3]);
    }
}
