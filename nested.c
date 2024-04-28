#include <stdio.h>


int findCube(int a)
{
    return a * a * a;
}

int findSquare(int a)
{
    return a * a;
}

void computeSum(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]%2==0){
            sum += findSquare(a[i]);
        }
        else{
            sum += findCube(a[i]);
        }
    }
    printf("Sum: %d\n", sum);
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    computeSum(a, 5);
    //Answer = 1^3+2^2+3^3+4^2+5^3 = 1+4+27+16+125 = 173
}