/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlength.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:10:50 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/20 19:21:47 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count(char const *str, char c)
{
	int i;
	int flag;
	int count;

	i = 0;
	flag = 0;
	count = 0;
	while (*str)
	{
		if (!flag && *str != c)
		{
			count++;
		}
		flag = (str[i] == c) ? 0 : 1;
		str++;
	}
	return (count);
}
