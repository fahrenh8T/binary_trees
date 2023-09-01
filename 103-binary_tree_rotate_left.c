#include "binary_trees.h"

/**
 *binary_tree_rotate_left - performs a left rotation on a binary tree
 *@tree: pointer to the tree to be rotated
 *
 *Return: pointer to the new root of the rotated tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rl_child, *new_root;

	rl_child = NULL;
	if (tree == NULL || tree->right == NULL)
		return (NULL);

	if (tree->right->left != NULL)
		rl_child = tree->right->left;

	new_root = tree->right;
	tree->right->left = tree;
	tree->parent = tree->right;
	tree->right->parent = NULL;
	tree->right = rl_child;

	if (rl_child != NULL)
		rl_child->parent = tree;

	return (new_root);
}
