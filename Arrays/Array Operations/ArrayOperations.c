#include<stdio.h>
#include<ctype.h>
#define size 20

void main()
{
    int a[size], n, i, opt;
    int pos, element;
    char choice;
    printf("Enter Size of the Array: ");
    scanf("%d",&n);
    printf("Enter %d Elements: ", n);
    for(i = 0 ; i < n ; i++)
        scanf("%d",&a[i]);
    do{
    printf("\
1) Insert at Beginning\t2) Insert at a Position\t3) Insert at End\n\
4) Delete at Beginning\t5) Delete at a Position\t6) Delete at End\n\
7) Search an Element\t8) Sort The Array\t9) Reverse the Array\t\t\n\
    ");
    printf("Select An Option: ");
    scanf("%d", opt);
    switch(opt)
    {
        case 1: printf("Enter the Element: ");
                scanf("%d",&element);
                for(i = 1 ; i < n ; i++)

    }
    }while(tolower(choice) == 'y');
}
