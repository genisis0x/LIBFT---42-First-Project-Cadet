/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:37:16 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/28 15:51:57 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			connection_checker(char *str)
{
	int	j;
	int	ad_block;

	j = 0;
	ad_block = 0;
	while (j < 20)
	{
		if (str[j] == '#')
		{
			if ((j + 1) < 20 && str[j + 1] == '#')
				ad_block++;
			if ((j - 1) >= 0 && str[j - 1] == '#')
				ad_block++;
			if ((j + 5) < 20 && str[j + 5] == '#')
				ad_block++;
			if ((j - 5) >= 0 && str[j - 5] == '#')
				ad_block++;
		}
		j++;
	}
	return (ad_block == 6 || ad_block == 8);
}

int			token_checker(char *str, int res)
{
	int pos;
	int no_block;

	pos = 0;
	no_block = 0;
	while (pos < 20)
	{
		if (pos % 5 < 4)
		{
			if (!(str[pos] == '#' || str[pos] == '.'))
				return (1);
			if (str[pos] == '#' && ++no_block > 4)
				return (2);
		}
		else if (str[pos] != '\n')
			return (3);
		pos++;
	}
	if (res == 21 && str[20] != '\n')
		return (4);
	if (!connection_checker(str))
		return (5);
	return (0);
}

void		find_max_min(char *s, t_point *min, t_point *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_tetris	*get_token(char *str, char value)
{
	char		**pos;
	int			i;
	t_point		*min;
	t_point		*max;
	t_tetris	*piece;

	i = 0;
	min = new_point(3, 3);
	max = new_point(0, 0);
	find_max_min(str, min, max);
	pos = (char **)ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], str + (min->x) + (i + min->y) \
				* 5, max->x - min->x + 1);
		i++;
	}
	piece = new_token(pos, max->x - min->x + 1, max->y - min->y + 1, value);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (piece);
}

t_list		*r_tetris(int fd)
{
	t_list		*list;
	t_tetris	*tetris;
	int			res;
	char		*buff;
	char		c;

	buff = ft_strnew(21);
	list = NULL;
	c = 'A';
	while ((res = read(fd, buff, 21)) >= 20)
	{
		if (token_checker(buff, res) != 0 || \
				(tetris = get_token(buff, c++)) == NULL)
		{
			ft_memdel((void **)&buff);
			return (ft_free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_tetris)));
		ft_memdel((void**)&tetris);
	}
	ft_memdel((void **)&buff);
	if (res != 0)
		return (ft_free_list(list));
	ft_reverse_list(&list);
	return (list);
}
