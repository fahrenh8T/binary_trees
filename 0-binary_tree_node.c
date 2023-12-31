#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary tree node.
 *
 * @parent: A pointer to the parent of the node.
 * @value: The value to be puted on the new node.
 *
 * Return: If it fails - NULL else - a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *host;

	host = malloc(sizeof(binary_tree_t));
	if (host == NULL)
		return (NULL);

	host->n = value;
	host->parent = parent;
	host->left = NULL;
	host->right = NULL;

	return (host);
}
