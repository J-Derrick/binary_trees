#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: node to be printed
 * @offset: Offset to print
 * @depth: node depth
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, val;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (val = 0; val < width; val++)
		s[depth][offset + left + val] = b[val];
	if (depth && is_left)
	{
		for (val = 0; val < width + right; val++)
			s[depth - 1][offset + left + width / 2 + val] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (val = 0; val < left + width; val++)
			s[depth - 1][offset - width / 2 + val] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - Determine height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: Height of the node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: root node of the tree to be printed
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, val, num;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (val = 0; val < height + 1; val++)
	{
		s[val] = malloc(sizeof(**s) * 255);
		if (!s[val])
			return;
		memset(s[val], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (val = 0; val < height + 1; val++)
	{
		for (num = 254; num > 1; --num)
		{
			if (s[val][num] != ' ')
				break;
			s[val][num] = '\0';
		}
		printf("%s\n", s[val]);
		free(s[val]);
	}
	free(s);
}
