#include "binary_trees.h"
/**
 * tree_height - function that measures the height
 * of a binary tree
 * @tree: pointer to root node of the tree to measure the height.
 * Return: height of the tree, 0 if null
 */

size_t tree_height(const binary_tree_t *tree)
{
	size_t x = 0, y = 0;

	if (!tree)
		return (0);
	x = tree_height(tree->left);
	y = tree_height(tree->right);
	if (x > y)
		return (x + 1);
	else
		return (y + 1);
}
/**
 * binary_tree_height - function that measures the height
 * of a binary tree
 * @tree: pointer to root node of the tree to measure the height.
 * Return: height of the tree, 0 if null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t r = 0;

	if (!tree)
		return (0);
	r = tree_height(tree) - 1;
	return (r);
}
