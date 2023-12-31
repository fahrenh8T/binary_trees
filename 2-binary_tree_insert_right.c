#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of a node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, NULL (failure or if parent is NULL)
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nnew;

	if (parent == NULL)
		return (NULL);

	nnew = binary_tree_node(parent, value);
	if (nnew == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		nnew->right = parent->right;
		parent->right->parent = nnew;
	}
	parent->right = nnew;

	return (nnew);
}
