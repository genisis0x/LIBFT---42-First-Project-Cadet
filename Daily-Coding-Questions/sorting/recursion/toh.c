/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:37:27 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/05 23:40:04 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void move (x, y)
{
	printf ("%c->%c\n", x, y);
}

void toh(int n,char x,char y,char z)
{
	if ( n > 1)
	{
		toh(n-1, x, z, y);
		move (x, y);
		toh(n-1, z, y, x);
	}
	else if (n == 1)
	{
		move (x, y);
	}
}

int main (void)
{
	toh (2, 'A', 'B', 'C');
	return (0);
}
