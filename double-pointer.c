#include <stdio.h>

int main(){
    int x = 100;
    int *p = &x;
    int **q = &p;
    (*q)++;
    (**q)++;
    printf("%p\n", p);
    return 0;
}