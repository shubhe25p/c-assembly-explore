#include<stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    char c;
    int rows=1;
    
    while((c = fgetc(fp)) != EOF)
    {
        char *c = (char *)malloc()
        if(c == '\n' && rows==1)
        {
            rows++;
        }
        

    }
    printf("\nRows: %d\n", rows);
    return 0;
}