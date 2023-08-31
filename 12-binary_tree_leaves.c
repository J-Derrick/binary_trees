#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree.
 * @tree: pointer to the root node.
 *
 * Return: size of leaf nodes.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int leaf_l = 0, leaf_r = 0;

	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left)
		leaf_l = binary_tree_leaves(tree->left);
	if (tree->right)
		leaf_r = binary_tree_leaves(tree->right);

	return (leaf_l + leaf_r);
}
