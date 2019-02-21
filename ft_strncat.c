/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:11:04 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/15 22:17:57 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != 0 && i < n)
	{
		s1[len++] = s2[i++];
	}
	s1[len] = '\0';
	return (s1);
}
