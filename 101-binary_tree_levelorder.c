#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: Height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * print_level - Prints a level in the binary tree
 * @tree: Pointer to the root node of the tree to print.
 * @level: Level of the tree to print.
 */
void print_level(const binary_tree_t *tree, size_t level)
{
    if (!tree)
        return;

    if (level == 1)
        printf("%d ", tree->n);
    else if (level > 1)
    {
        print_level(tree->left, level - 1);
        print_level(tree->right, level - 1);
    }
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t height, level;

    if (!tree || !func)
        return;

    height = binary_tree_height(tree);

    for (level = 1; level <= height; level++)
        print_level(tree, level);
}
