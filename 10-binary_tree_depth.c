#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node
 *
 * Return: depth of node or NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t deep = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		deep++;
		tree = tree->parent;
	}

	return (deep);
}
