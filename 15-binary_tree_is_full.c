#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: pointer to root of the tree.
 *
 * Return: T/F
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int value = 0, num = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left && tree->right)
	{
		num = binary_tree_is_full(tree->left);
		value = binary_tree_is_full(tree->right);
	}
	if (num == value && num == 1)
		return (1);
	return (0);
}
