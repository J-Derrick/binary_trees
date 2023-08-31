#include "binary_trees.h"

/**
 * binary_tree_size - find binary tree size.
 * @tree: pointer to the root node of the tree to find the size.
 *
 * Return: Zero
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t right_size = 0, left_size = 0;

	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (1);

	if (tree->left)
		left_size = binary_tree_size(tree->left);
	if (tree->right)
		right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}


/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: True or False
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0, right_height = 0, left_height = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		height = left_height;
	else
		height = right_height;

	return (height + 1);
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0, left_size = 0, right_size = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	if (left_height == right_height && left_size == right_size)
	{
		return (1);
	}

	return (0);
}
