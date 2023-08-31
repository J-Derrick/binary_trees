#include "binary_trees.h"
/**
 * binary_tree_insert_left - function that inserts a node as the left-child
 * of another node
 * @parent: is a pointer to the node to insert the left-child in
 * @value:  value to store in the created node
 *
 * Return: created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *created = NULL;
	binary_tree_t *val = NULL;

	if (!parent)
		return (NULL);

	created = malloc(sizeof(binary_tree_t));
	if (!created)
		return (NULL);
	created->n = value;
	created->parent = parent;
	created->right = NULL;
	if (parent->left)
	{
		val = parent->left;
		parent->left = created;
		created->left = val;
		val->parent = created;
	}
	else
	{
		parent->left = created;
		created->left = NULL;
	}
	return (created);
}

