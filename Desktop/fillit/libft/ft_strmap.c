/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 20:41:17 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/16 21:45:58 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	t_int	i;
	char	*res;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(s))))
		return (NULL);
	ft_strcpy(res, s);
	while (res[i])
	{
		res[i] = f(res[i]);
		i++;
	}
	return (res);
}
