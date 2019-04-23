/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 19:37:28 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/22 20:25:02 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

t_bst *ft_new_node(int value) // function to create a new node
{
	t_bst *new;
	if (!(new = (t_bst *)malloc(sizeof(t_bst))))
		return NULL;
	new->value = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int ft_search_index(int start, int end, int inf[], int ele) // will give the index of infix expression
{
	while (start <= end)
	{
		if (inf[start] == ele)
			return start;
		start++;
	}
	return (0);

}

t_bst *insert(t_bst *root, int item)
{
	if (!root)
	{
		root = new_node(item);
	}
	else if (item <= root->value)
		root->left = insert(root->left, item);
	else
		root->right = insert(root->right, item);
	return root;
}

t_bst *ft_tree_maker(int inf[], int pre[], int start, int end) // will make the tree recursively 
{
	static int pre_index = 0; // initilize this prefix index to static because it should be itilized only once.
	if (start > end)
		return NULL;
	t_bst *t_node = ft_new_node(pre[pre_index++]); // create the new node
	if (start == end)
		return t_node;
	int inf_index = ft_search_index(start, end, inf, t_node->value); 
	t_node->left = ft_tree_maker(inf, pre, start, inf_index -1); // BFS for the left node by reducing the end point to left of infix index
	t_node->right = ft_tree_maker(inf, pre, inf_index + 1, end); // BFS for the right node by reducing the start point to right of infix index

	return t_node; // return the node 
}

void print_post_fix(t_bst *t) // printing the postfix expresion
{
	if (t == NULL)
		return ;
	print_post_fix(t->left);
	print_post_fix(t->right);
	printf("%d \n", t->value);
}

void print_in_fix(t_bst *t) // printing the postfix expresion
{
	if (t == NULL)
		return;
	print_in_fix(t->left);
	printf("%d \n", t->value);
	print_in_fix(t->right);
	
}