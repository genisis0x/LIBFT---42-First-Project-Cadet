/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:49:42 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/17 17:10:41 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t i;
	size_t j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (ft_strwhitespace(s[i]))
		i++;
	while (ft_strwhitespace(s[j - 1]))
		j--;
	if (i > j)
		j = i;
	return (ft_strsub(s, i, j - i));
}
