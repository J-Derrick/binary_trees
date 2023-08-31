#include "binary_trees.h"

/**
 * binary_tree_is_root - check if a node is a root.
 * @node: node to be checked
 * Return: True or False
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node && node->parent == NULL)
		return (1);
	return (0);
}
