#include <stdio.h>

int main(){
    int  arr[] = {5,4,3,2};
    int len = *(&arr + 1) - arr;
    printf("Length of array = %d\n", len);
    return 0;

}