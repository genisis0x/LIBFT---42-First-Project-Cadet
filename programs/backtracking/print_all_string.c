/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:28:36 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/09 03:16:49 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*************************This function will display all the different no of combinations in the String*****************************/

#include <stdio.h>
void swap(char *a, char *b)// swap function
{
	char temp;
	temp  = *a;
	*a = *b;
	*b = temp;
}

void permutation(char *str, int start, int end)
{
	if (start == end)
		printf("%s\n", str);
	else
		for (int i = start; i <= end; i++)
		{
			swap(&str[start], &str[i]); // swap will make the function again 
			permutation(str, start + 1, end); // recursive call 
			swap(&str[i], &str[start]); // backtracking again to the same position
		}
}
#include <string.h>
int main (int ac, char **av) // main driver
{
	if (ac == 2)
	{
		permutation(av[1], 0, strlen(av[1]) - 1);
	}
	printf("\n");
	return 0;
}
