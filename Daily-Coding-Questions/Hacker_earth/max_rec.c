
int max(int a, int b)
{
    if (a < b)
    {
        return b;
    }
    return a;
}
int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    return a;
}

#include <stdio.h>
int max_rec(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int breath =  min(x2, x4) - max(x1, x3);
    if (breath < 0) return 0;
    int length = (min(y3, y1) - max(y2, y4));
    if(length < 0) return 0;
    printf("The value of length and breath is %d && %d\n", length, breath);
    return (length * breath); 
}
#include "stdio.h"
int main (void)
{
    printf("The intersection area is: %d\n", max_rec(2, 5, 5, 1, 3, 7, 5, 2));
    printf("The intersection area is: %d\n", max_rec(2, 2, 5, 7, 3, 4, 6, 9));
}