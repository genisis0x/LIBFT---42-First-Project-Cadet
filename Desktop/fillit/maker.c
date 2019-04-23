/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:16:13 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/28 15:51:32 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		sqt_func(int n)
{
	int	side;

	side = 2;
	while (side * side < n)
		side++;
	return (side);
}

t_map	*map_new(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)malloc(sizeof(t_map));
	map->size = size;
	map->arr = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->arr[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->arr[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

t_map	*solve(t_list *list)
{
	int		size;
	t_map	*map;

	size = sqt_func(ft_len_lst(list) * 4);
	map = map_new(size);
	while (!map_solver(map, list))
	{
		size++;
		free_map(map);
		map = map_new(size);
	}
	return (map);
}
