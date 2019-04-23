/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:18:31 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/28 15:51:29 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(t_map *m)
{
	int i;

	i = 0;
	while (i < m->size)
	{
		ft_putstr(m->arr[i]);
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	t_list	*list;
	t_map	*map;

	if (ac != 2)
	{
		ft_putstr("usage: Put valid input_file\n");
		return (1);
	}
	if ((list = r_tetris(open(av[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	map = solve(list);
	print_map(map);
	free_map(map);
	ft_free_list(list);
	return (0);
}
