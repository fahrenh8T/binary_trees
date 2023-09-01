#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation on a binary tree
 *@tree: pointer to the tree to be rotated
 *
 *Return: pointer to the new root of the rotated tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *lr_child, *new_root;

	lr_child = NULL;
	if (tree == NULL || tree->left == NULL)
		return (NULL);

	if (tree->left->right != NULL)
		lr_child = tree->left->right;

	new_root = tree->left;
	tree->left->right = tree;
	tree->parent = tree->left;
	tree->left->parent = NULL;
	tree->left = lr_child;

	if (lr_child != NULL)
		lr_child->parent = tree;

	return (new_root);
}
