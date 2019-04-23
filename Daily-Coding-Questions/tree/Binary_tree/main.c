/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:19:02 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/22 20:22:12 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"
int main (void)
{
	t_bst *root = NULL;
	
	printf("Insert the nodes 15, 10, 20, 25, 8, 12\n");
	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 25);
	root = insert(root, 8);
	root = insert(root, 12);

	printf("---------------------------------------\n");
	printf("---------------------------------------\n");
	
	printf("Searching the element 25\n");
	if (search(root,25) == 1)
	{
		printf("Found the element 25\n");
	}
	else 
	{
		printf("Didn't Found the element 12\n");
	}
	
	printf("---------------------------------------\n");
	printf("---------------------------------------\n");
	
	int inf[] = {4, 2, 5, 1, 6, 3};
	int pre[] = {1, 2, 4, 5, 3, 6};
	int len = sizeof(inf) / sizeof(inf[0]);
	t_bst *tree = ft_tree_maker(inf, pre, 0, len - 1);
	printf("The post_fix form of the tree is\n");
	print_post_fix(tree);
	
	printf("---------------------------------------\n");
	printf("---------------------------------------\n");
	
	printf("The height of the tree is %d\n", height_tree(root));
	
	printf("---------------------------------------\n");
	printf("---------------------------------------\n");
	
	printf("The infix form before deleting element 10 is\n");
	print_in_fix(root);
	
	printf("---------------------------------------\n");
	printf("---------------------------------------\n");
	
	root  = delete_node(root, 10);
	printf("The infix form after deleting 20 is\n");
	print_in_fix(root);
	return 0;
}
