/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:08:58 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/27 21:08:40 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *link;

	if (!(link = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		link->content = ft_memalloc(content_size);
		if (!(link->content))
		{
			free(link);
			return (NULL);
		}
		ft_memcpy(link->content, content, content_size);
	}
	link->content_size = content_size;
	link->next = NULL;
	return (link);
}
