#include "binary_trees.h"

/**
 * binary_tree_depth - find the tree depth
 * @tree: pointer to the node.
 *
 * Return: size of depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t ck = 0;

	if (tree == NULL || (tree->parent == NULL))
		return (0);
	ck = 1 + binary_tree_depth(tree->parent);
	return (ck);
}
