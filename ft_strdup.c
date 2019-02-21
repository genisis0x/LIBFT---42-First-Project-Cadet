/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:46:55 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/17 16:45:45 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == 0)
	{
		return (NULL);
	}
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
