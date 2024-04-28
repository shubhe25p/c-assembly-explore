#include <stdio.h>

int main()
{


    char str[]="Grade";

    char *ptr_ch;

    ptr_ch= &str[0];

    ptr_ch = ptr_ch+2;
    printf("%p",ptr_ch);
    int y,x=5;

y = *((int *)&x);
    printf("%d\n",y);
    printf("%p", &x);
    return 0;
}