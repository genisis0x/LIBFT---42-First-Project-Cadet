/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlength.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:10:50 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/19 18:30:32 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_countlength(s ,c)
{
	int i;
	int flag;
	int len;

	i = 0;
	flag = 0;
	len = 0;
	while (*s)
	{
		if (!flag && *s != c)
		{
			count++;
		}
		flag = (s[i] == c) ? 0 : 1;
		s++;
	}
	return(len);
}
