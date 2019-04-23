/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:11:38 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/16 21:42:49 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)src;
	i = 0;
	if (s > d)
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	if (d > s)
		while (len > 0)
		{
			len--;
			*(d + len) = *(s + len);
		}
	return (dst);
}
