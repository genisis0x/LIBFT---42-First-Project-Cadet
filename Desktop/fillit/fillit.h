/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 14:59:32 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/28 15:55:58 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_tetris
{
	char		**piece_pos;
	int			length;
	int			breadth;
	char		c;
}				t_tetris;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_map
{
	int			size;
	char		**arr;
}				t_map;

t_list		*r_tetris(int fd);
t_tetris	*get_token(char *str, char value);
void		find_max_min(char *s, t_point *min, t_point *max);
int			token_checker(char *str, int res);
int			connection_checker(char *str);
t_tetris	*new_token(char **pos, int l, int b, char value);
t_point		*new_point(int a, int b);
void		ft_reverse_list(t_list **begin_list);
int			sqt_func(int n);
t_map		*map_new(int size);
t_map		*solve(t_list *list);
void		put_token(t_tetris *tetri, t_map *map, t_point *point, char c);
int			poistion_check(t_tetris *tetri, t_map *map, int i, int j);
int			map_solver(t_map *map, t_list *list);
int			ft_len_lst(t_list *l);
void		free_map(t_map *map);
t_list		*ft_free_list(t_list *list);
void		print_map(t_map *map);
void		ft_free_token(t_tetris *tetri);
#endif
