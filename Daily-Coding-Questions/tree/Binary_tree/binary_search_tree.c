/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:38:26 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/22 20:25:05 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"
int search(t_bst *root, int item)
{
	if(!root) return 0;
	if(root->value == item) return 1;
	else if (item <= root->value)
	{
		return search(root->left, item);
	}
	else
	{
		return search(root->right, item);
	}
}
