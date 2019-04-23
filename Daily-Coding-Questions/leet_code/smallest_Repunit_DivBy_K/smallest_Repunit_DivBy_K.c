/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_Repunit_DivBy_K.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 22:16:20 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/29 22:16:30 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int smallestRepunitDivByK(int K) 
{
 for(int i = 0, nb = 0; i <= K; i++)
    {
        if((nb = (nb*10 + 1) % K) == 0)
            return i + 1;
    }
    return -1;
}

int main(void)
{
    printf("The length of the string is %d",smallestRepunitDivByK(3));
}
