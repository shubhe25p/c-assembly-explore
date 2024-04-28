#include <stdio.h>

void foo(int *x, int *y)
{  
    int t;
   if ( *x > *y ) { 
        t = *y; 
        *y = *x; 
        *x = t; 
    }
}

int main()
{  int a=3, b=2, c=1;
   foo(&a, &b);
   foo(&b, &c);
   foo(&a, &b);
   printf("a=%d b=%d c=%d\n", a, b, c);
   return 0;
}