#include <stdio.h>

void sumnaive(int p){
    p = p + 1;
}

void sumptr(int *p){
    *p = *p + 1;
}

int main(){
    int p = 1;
    sumnaive(p);
    printf("Sum naive= %d\n", p);
    sumptr(&p);
    printf("Sum Pointer = %d\n", p);
    return 0;
}