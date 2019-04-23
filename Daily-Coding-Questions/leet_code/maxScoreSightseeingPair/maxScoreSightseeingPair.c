/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxScoreSightseeingPair.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:00:11 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/29 23:00:27 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
int maxScoreSightseeingPair(int* A, int ASize) 
{

    int result = 0;
    int best_pre = 0;
    for(int i = 0; i < ASize; i++)
    {
        result = fmax(result, A[i] - i + best_pre);
        best_pre = fmax(A[i] + i, best_pre);
    }
    return (result);
}

int main (void)
{
    int A[] = {8, 1, 5, 2, 6};
    printf("The maximunm sightseeingPair Value is %d",maxScoreSightseeingPair(A, 5));
}
