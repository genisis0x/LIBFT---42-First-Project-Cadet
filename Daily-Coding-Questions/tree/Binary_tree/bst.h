/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:15:28 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/22 20:25:04 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a, b) (a < b) ? b : a

typedef struct Bst_Node
{
	int value;
	struct Bst_Node *left;
	struct Bst_Node *right;
} t_bst;

t_bst *ft_new_node(int value);
int height_tree(t_bst *node);
t_bst *new_node(int data);
t_bst *insert(t_bst *root, int item);
int ft_search_index(int start, int end, int inf[], int ele);
t_bst *ft_tree_maker(int inf[], int pre[], int start, int end);
void print_post_fix(t_bst *t);
void print_in_fix(t_bst *t);
int search(t_bst *root, int item);
t_bst *delete_node(t_bst *root, int value);