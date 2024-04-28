#include <stdio.h>

typedef struct {
    int x;
    int y;
} point;

int main(){
    point p;
    p.x = 5;
    p.y = 10;
    printf("x = %d, y = %d\n", p.x, p.y);
    point *ptr = &p;
    ptr->x = 10;
    ptr->y = 20;
    printf("x = %d, y = %d\n", p.x, p.y);
    return 0;
}