#include "binary_trees.h"

/**
 * print_t - recursively generates a formatted representation of a binary tree
 * @tree: pointer to the root node of binary tree
 * @offset: offset for current node's placement
 * @depth: current depth of tree
 * @ft: array used to store the formatted tree representation
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **ft)
{
	char str[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(str, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, ft);
	right = print_t(tree->right, offset + left + width, depth + 1, ft);
	for (i = 0; i < width; i++)
		ft[depth][offset + left + i] = str[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			ft[depth - 1][offset + left + width / 2 + i] = '-';
		ft[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			ft[depth - 1][offset - width / 2 + i] = '-';
		ft[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - height of a binary tree
 * @tree: pointer to the root node of the tree; measures the height
 *
 * Return: The height of the binary tree
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t hght_l;
	size_t hght_r;

	hght_l = tree->left ? 1 + _height(tree->left) : 0;
	hght_r = tree->right ? 1 + _height(tree->right) : 0;
	return (hght_l > hght_r ? hght_l : hght_r);
}

/**
 * binary_tree_print - prints a binary tree with proper formatting
 * @tree: pointer to the root node of the binary tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **t_lines;
	size_t hght, i, j;

	if (!tree)
		return;
	hght = _hght(tree);
	t_lines = malloc(sizeof(*t_lines) * (hght + 1));
	if (!t_lines)
		return;
	for (i = 0; i < hght + 1; i++)
	{
		t_lines[i] = malloc(sizeof(**t_lines) * 255);
		if (!t_lines[i])
			return;
		memset(t_lines[i], 32, 255);
	}
	print_t(tree, 0, 0, t_lines);
	for (i = 0; i < hght + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (t_lines[i][j] != ' ')
				break;
			t_lines[i][j] = '\0';
		}
		printf("%s\n", t_lines[i]);
		free(t_lines[i]);
	}
	free(t_lines);
}
