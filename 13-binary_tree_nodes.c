#include "binary_trees.h"

/**
 * binary_tree_nodes - function that counts the nodes with at least 1 child
 * @tree: pointer to the root node of the tree to measure the size
 * Return: number of nodes if tree is null 0
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	if (tree->left || tree->right)
	{
		return (1 + binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right));
	}
	return (0);
}
