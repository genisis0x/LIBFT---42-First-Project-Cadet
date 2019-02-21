/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:48:16 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/17 00:31:43 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		res[i] = f(i, res[i]);
		i++;
	}
	return (res);
}
