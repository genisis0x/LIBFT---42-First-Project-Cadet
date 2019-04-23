/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_Binary_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:07:35 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/22 20:25:00 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

t_bst *find_min(t_bst *root)
{
    while(root->left != NULL)
        root = root->left;
    return root;

}

t_bst *delete_node(t_bst *root, int value)
{
    if(root == NULL) return root;
    else if(root->value > value) root->left = delete_node(root->left, value);
    else if(root->value < value) root->right = delete_node(root->right, value);
    else
    {
        // Case 1: No child or is_a_leaf
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // Case 2: 1 chid
        else if (root->left == NULL || root->right == NULL)
        {
            if (root->left == NULL)
            {
                t_bst *temp = root;
                root = root->right;
                free(temp);
            }
            else
            {
                t_bst *temp = root;
                root = root->left;
                free(temp);
            }
        }
        // Case 3
        else
        {
            t_bst *temp = find_min(root->right);
            root->value = temp->value;
            root->right = delete_node(root->right, temp->value);
        }
    }
    return root;
}