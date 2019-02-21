/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:00:29 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/15 22:13:31 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	int				new_n;
	unsigned char	to_find;

	i = 0;
	to_find = (unsigned char)c;
	new_n = (int)n;
	while (i < new_n)
	{
		if (((unsigned char*)s)[i] == to_find)
		{
			return (&((unsigned char*)s)[i]);
		}
		else
			i++;
	}
	return (NULL);
}
