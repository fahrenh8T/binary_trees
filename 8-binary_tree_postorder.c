#include "binary_trees.h"

/**
 * binary_tree_postorder - goes throuh a binary tree using post-roder travesal
 * @tree: pointer to the root node
 * @func: pointer to funcation that call s each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
