#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct StudentAttributes
{
    int roll, hr, min, sec;
    char name[30];
} *s;

void swap(int i, int j)
{
    int temp;
    char t[30];

    strcpy(t, s[i].name); strcpy(s[i].name, s[j].name); strcpy(s[j].name, t);

    temp = s[i].roll; s[i].roll = s[j].roll; s[j].roll = temp;

    temp = s[i].hr; s[i].hr = s[j].hr; s[j].hr = temp;

    temp = s[i].min; s[i].min = s[j].min; s[j].min = temp;

    temp = s[i].sec; s[i].sec = s[j].sec; s[j].sec = temp;
}

void main()
{
    int n, i, j;
    printf("How Many Students took the test: ");
    scanf("%d", &n);
    s = (struct StudentAttributes*) malloc(n * sizeof(struct StudentAttributes));

    //Taking Details of All Students as Input
    for(i = 0 ; i < n ; i++){
        printf("Student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll Number: ");
        scanf("%d",&s[i].roll);
        printf("Time Taken [hh:mm:ss]: ");
        scanf("%d:%d:%d", &s[i].hr, &s[i].min, &s[i].sec);
        printf("\n");
    }

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n-i-1 ; j++){
            if(s[j].hr > s[j+1].hr){
                swap(j, j+1);
            }
            else if((s[j].hr == s[j+1].hr) && (s[j].min > s[j+1].min)){
                swap(j, j+1);
            }
            else if((s[j].hr == s[j+1].hr) && (s[j].min == s[j+1].min) && (s[j].sec > s[j+1].sec)){
                swap(j, j+1);
            }
            else if((s[j].hr == s[j+1].hr) && (s[j].min == s[j+1].min) && (s[j].sec == s[j+1].sec) && (s[j].roll > s[j+1].roll)){
                swap(j, j+1);
            }
        }
    }

    for(i = 0 ; i < n ; i++){
        printf("Name: %-15s RollNo.: %-3d TimeTaken: %.2d:%.2d:%.2d\n", s[i].name, s[i].roll, s[i].hr, s[i].min, s[i].sec);
    }
}
