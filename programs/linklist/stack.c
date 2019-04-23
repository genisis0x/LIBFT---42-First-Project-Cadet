/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 22:18:21 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/09 00:51:31 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
typedef struct node
{
	int				data;
	struct	node	*next;
}					t_list;

t_list *head;

t_list *ft_create(int item) // function will create the list and return the list by setting the value of list to the item.
{
	t_list *res = (t_list *)malloc(sizeof(t_list));
	res->data = item;
	res->next = NULL;
	return (res);
}

void push (int item)
{
	t_list *new;
	if (!(new = ft_create(item))) // overflow condition when heap is full.
		return ;
	new->next = head;
	head = new;
}

int pop()
{
	int item = 0;
	t_list *temp = ft_create(0);
	if (head == NULL) // stack is empty or underflow
	{
		return (-1);
	}
	else
	{
		item = head->data; // store value of the item to written
		temp = head; // temp will be holding the value of head which is been pointed by
		head = head->next; // move the head by one position in the list
		free(temp); // free the list from the memory now
		return (item);
	}
}

#include <stdio.h>
int main (void)
{
	push(1);
	push(2);
	push(3);
	printf("%d", pop());
	printf("%d", pop());
	printf("%d", pop());
	printf("%d", pop());
	return 0;
}




