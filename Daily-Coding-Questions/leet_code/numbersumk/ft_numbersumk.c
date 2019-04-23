/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbersumk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:13:32 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/23 16:19:40 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INT_MAX 2147483647 // Take all the int values which can be considered for, fast exectution change INT_MAx to a small digit of thousand's or hundred.

bool ft_numsum(int *a, int final_sum, size_t size)
{
	size_t i = 0;
	int hash_map [INT_MAX] = {0}; // this will take time to initilize all the values to 0 because int max is a big number
	int find_num;

	while (size > i)
	{
		find_num = final_sum - a[i];
		if (hash_map[find_num] == 1 ) // Hash_MAP for the value's
		{
			return (true);
		}
		hash_map[a[i]] = 1; // Set the array value in Hash_Map.
		i++;
	}
	return (false);
}

int main (void)
{
	int a[4] = {10, 15, 3, 7};
	size_t size = (sizeof(a)) / (sizeof(a[0])); // size of Array
	int final_sum = 17;
	bool b = ft_numsum(a, final_sum, size);
	printf(b ? "true" : "false");
	return (0);
}
