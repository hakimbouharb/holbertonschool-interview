#include "binary_trees.h"

/**
 * rec_avl_tree - Builds an AVL tree
 * @parent: pointer
 * @arr: pointer to the head
 * @start: start index
 * @end: end index
 * Return: pointer or NULL on failure
 */
avl_t *rec_avl_tree(avl_t *parent, int *arr, size_t start, size_t end)
{
	avl_t *next;
	size_t idx = (start + end) / 2;

	next = malloc(sizeof(avl_t));
	if (!next)
		return (NULL);
	next->n = arr[idx];
	next->parent = parent;
	next->right = NULL;
	next->left = NULL;
	if (!next)
		return (NULL);
	if (idx != end)
		next->right = rec_avl_tree(next, arr, idx + 1, end);
	if (idx != start)
		next->left = rec_avl_tree(next, arr, start, idx - 1);

	return (next);
}

/**
 * sorted_array_to_avl - Builds an AVL tree
 * @array: pointer to head
 * @size: size of array
 * Return: pointer or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (!array)
		return (NULL);
	if (size == 0)
		return (NULL);
	tree = rec_avl_tree(NULL, array, 0, size - 1);

	return (tree);
}
