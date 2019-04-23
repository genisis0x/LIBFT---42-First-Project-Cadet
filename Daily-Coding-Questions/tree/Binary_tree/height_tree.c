#include "bst.h"

int height_tree(t_bst *node)
{
    if(!node) return -1;
    else return 1 + (max(height_tree(node->left), height_tree(node->right)));
}

t_bst *new_node(int data)
{
    t_bst *node = (t_bst *)malloc(sizeof(t_bst));
    node->value = data;
    node->left = node->right = NULL;
    return node;
}