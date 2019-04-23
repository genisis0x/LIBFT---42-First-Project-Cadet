/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:22:30 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/28 15:52:08 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_token(t_tetris *tetri, t_map *map, t_point *p, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetri->breadth)
	{
		j = 0;
		while (j < tetri->length)
		{
			if (tetri->piece_pos[j][i] == '#')
			{
				map->arr[p->y + j][p->x + i] = c;
			}
			j++;
		}
		i++;
	}
	ft_memdel((void **)&p);
}

int		poistion_check(t_tetris *tetri, t_map *map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetri->breadth)
	{
		j = 0;
		while (j < tetri->length)
		{
			if (tetri->piece_pos[j][i] == '#' && \
					(map->arr[y + j][x + i] != '.'))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	put_token(tetri, map, new_point(x, y), tetri->c);
	return (1);
}

int		map_solver(t_map *map, t_list *list)
{
	int			i;
	int			j;
	t_tetris	*tetri;

	if (list == NULL)
		return (1);
	j = 0;
	tetri = (t_tetris *)(list->content);
	while (j < map->size - (tetri->length) + 1)
	{
		i = 0;
		while (i < map->size - (tetri->breadth) + 1)
		{
			if (poistion_check(tetri, map, i, j))
			{
				if (map_solver(map, list->next))
					return (1);
				else
					put_token(tetri, map, new_point(i, j), '.');
			}
			i++;
		}
		j++;
	}
	return (0);
}
