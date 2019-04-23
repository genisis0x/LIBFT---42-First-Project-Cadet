// Complete the sockMerchant function below.
#include "stdio.h"
int sockMerchant(int n, int ar_count, int* ar) 
{
    int i = 0, pair_Socks= 0;
    int arr[101] = {0};
    while(i < ar_count)
    {
        arr[ar[i]] = arr[ar[i]] + 1;
        i++;
    }
    i = 0;
    while( i < ar_count)
    {
        if(arr[ar[i]] > 0)
        {
            pair_Socks = pair_Socks + arr[ar[i]] / 2;
            arr[ar[i]] = 0;
            printf("%d",pair_Socks);
        }
        i++;
    }
    return pair_Socks;
}
#include <stdio.h>
int main (void)
{
    int ar[100] = {44,55,11,15,4,72,26,91,80,14,43,78,70,75,36,83,78,91,17,17,54,65,60,21,58,98,87,45,75,97,81,18,51,43,84,54,66,10,44,45,23,38,22,44,65,9,78,42,100,94,58,5,11,69,26,20,19,64,64,93,60,96,10,10,39,94,15,4,3,10,1,77,48,74,20,12,83,97,5,82,43,15,86,5,35,63,24,53,27,87,45,38,34,7,48,24,100,14,80,54};
    printf("%d", sockMerchant(100, 100, ar));
}