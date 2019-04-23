/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 22:10:04 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/28 15:51:26 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_reverse_list(t_list **alst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

t_point		*new_point(int a, int b)
{
	t_point *p;

	p = ft_memalloc(sizeof(t_point));
	p->x = a;
	p->y = b;
	return (p);
}

t_tetris	*new_token(char **pos, int b, int l, char value)
{
	t_tetris *new;

	new = (t_tetris *)malloc(sizeof(t_tetris));
	new->piece_pos = pos;
	new->length = l;
	new->breadth = b;
	new->c = value;
	return (new);
}

int			ft_len_lst(t_list *l)
{
	int count;

	count = 0;
	while (l)
	{
		l = l->next;
		count++;
	}
	return (count);
}
