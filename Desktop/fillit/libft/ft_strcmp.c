/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:37:34 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/16 00:13:56 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s3;
	unsigned char	*s4;

	i = 0;
	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	while ((s3[i] || s4[i]) != 0)
	{
		if (s3[i] == s4[i])
		{
			i++;
		}
		else
			return (s3[i] - s4[i]);
	}
	return (0);
}
