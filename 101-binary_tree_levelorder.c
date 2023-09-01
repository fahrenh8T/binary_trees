#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 *print_level - recursively prints nodes of a binary tree at a specific level
 *@node: pointer to current node
 *@func: pointer to a function to apply to node values
 *@level: target level for printing nodes
 */
void print_level(binary_tree_t *node, void (*func)(int), int level)
{
	if (node != NULL && func != NULL)
	{
		if (level == 1)
			func(node->n);
		if (level > 1)
		{
			print_level(node->left, func, level - 1);
			print_level(node->right, func, level - 1);
		}
	}
}

/**
 *binary_tree_levelorder - traverse a binary tree using level-order traverse
 *@tree: pointer to the tree
 *@func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = 0;
	size_t task;
	binary_tree_t *cp_tree = (binary_tree_t *)tree;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (task = 0; task <= height + 1; task++)
		print_level(cp_tree, func, task);
}
