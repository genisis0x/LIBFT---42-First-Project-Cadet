/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:45:23 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/19 17:27:38 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_strsplit(char const *s, char c)
{
	char **res;
	int i;
	int len;
	int j;

	i = 0;
	len = ft_countlength(s, c);
	*res = (char **)malloc(sizeof(char) * (len + 1));
	j = 0;
	res[len] = '\0';
	len = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
		{
			;
		}
		while (s[j] && s[j] != c)
		{
			res[len] = s[j];
			j++;
		}
		j++;
	}

}
