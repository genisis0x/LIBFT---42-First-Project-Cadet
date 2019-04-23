/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 22:10:47 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/28 15:50:56 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->arr[i]));
		i++;
	}
	ft_memdel((void **)&(map->arr));
	ft_memdel((void **)&map);
}

void		ft_free_token(t_tetris *tetri)
{
	int y;

	y = 0;
	while (y < tetri->length)
	{
		ft_memdel((void **)(&(tetri->piece_pos[y])));
		y++;
	}
	ft_memdel((void **)(&(tetri->piece_pos)));
	ft_memdel((void **)&tetri);
}

t_list		*ft_free_list(t_list *list)
{
	t_list		*temp;
	t_tetris	*tetris;

	while (list)
	{
		tetris = (t_tetris *)(list->content);
		temp = list->next;
		ft_free_token(tetris);
		ft_memdel((void **)&list);
		list = temp;
	}
	return (NULL);
}
