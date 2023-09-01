#include "binary_trees.h"
#include "11-binary_tree_size.c"

/**
 * is_complete - checks if a binary tree is complete or not
 * @tree: pointer to the root of the tree
 * @index: index for left & right child
 * @tnode: total number of nodes in the tree
 *
 * Return: 1 (complete), 0 (not complete)
 */
int is_complete(const binary_tree_t *tree, int index, int tnode)
{
	if (tree == NULL)
		return (1);

	if (index >= tnode)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, tnode) &&
			is_complete(tree->right, 2 * index + 2, tnode));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete or not
 * @tree: pointer to the root of the tree
 *
 *  Return: 1 (complete), 0 (not complete)
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int host = binary_tree_size(tree);
	int index = 0;

	if (tree == NULL)
		return (0);
	return (is_complete(tree, index, host));
}
