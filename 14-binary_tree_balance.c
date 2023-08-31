#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0, right_height = 0, left_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = binary_tree_height(tree->left);
	if (tree->right)
		right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		height = left_height;
	else
		height = right_height;

	return (height + 1);
}


/**
 * binary_tree_balance - checks balance factor of a binary tree
 * @tree: pointer to the root node of the tree to findthe height.
 *
 * Return: 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right_height = 0, left_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = binary_tree_height(tree->left);

	if (tree->right)
		right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
