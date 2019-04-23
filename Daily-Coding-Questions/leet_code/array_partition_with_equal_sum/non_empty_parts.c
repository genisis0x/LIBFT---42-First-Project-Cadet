/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_empty_parts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 23:49:12 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/28 23:53:09 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
int sum(int *B, int ASize)
{
    int sum = 0;
    for (int i = 0; i < ASize; i++)
    {
        sum += B[i];
    }
    return(sum);
}

bool canThreePartsEqualSum(int* A, int ASize) 
{
    if (ASize == 2) return false;
    int total_sum = sum(A, ASize);
    int current_sum = 0;
    if (total_sum % 3 != 0) return false;
    printf("the value of total sum is %d\n", total_sum);
    int a = -1 , b = -1 , c = -1;
    for(int i = 0; i < ASize; i++)
    {
        current_sum += A[i];
        if (current_sum == total_sum / 3)
        {
            if (a < 0) { a = i, current_sum = 0;}
            else if (b < 0){ b = i, current_sum = 0;}
            else c = i;
        }
    }
    printf("The value of a %d\n" "The value of b %d\n" "The value of c is %d\n", a, b, c);
    return (a >= 0 && b >= 0 && c >= 0 && a < b && b < c && (c ==  ASize - 1));
}


int main(void)
{
    int a[] = {0,2,1,-6,6,-7,9,1,2,0,1};
    bool result = canThreePartsEqualSum(a, 11);
    printf("The bool value is %i", result);
}
