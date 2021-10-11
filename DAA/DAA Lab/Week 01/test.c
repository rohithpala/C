#include<stdio.h>

struct StudentAttributes
{
    int roll, hr, min, sec;
    char name[30];
} *s;

void main()
{
    int n, i;
    printf("How Many Students took the test: ");
    scanf("%d", &n);
    s = (struct StudentAttributes*) malloc(n * sizeof(struct StudentAttributes));

    for(i = 0 ; i < n ; i++){
        printf("Roll Number: ");
        scanf("%d",&s->roll);
    }

    for(i = 0 ; i < n ; i++){
        printf("%d", s[i].roll);
    }
}
