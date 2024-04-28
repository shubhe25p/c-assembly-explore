#include <stdio.h>

int main(){
    printf("Hello Pointer world \n");
    int a=5;
    printf("%p \n", &a);
    int *p;
    p=&a;
    *p=15;
    printf("%d \n", *p);
    return 0;
}
