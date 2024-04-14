#include "binary_trees.h"
#include "120-binary_tree_is_avl.c"
#include "103-binary_tree_rotate_left.c"
#include "104-binary_tree_rotate_right.c"

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: A pointer to the root node of the AVL tree.
 * @value: The value to remove from the AVL tree.
 *
 * Return: A pointer to the root node of the AVL tree after removal, or NULL on failure.
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return (NULL);

    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            avl_t *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {
            avl_t *temp = root->right;

            while (temp->left != NULL)
                temp = temp->left;

            root->n = temp->n;

            root->right = avl_remove(root->right, temp->n);
        }
    }

    if (root == NULL)
        return (NULL);

    root->height = 1 + MAX(avl_height(root->left), avl_height(root->right));

    int balance = avl_balance(root);

    if (balance > 1 && avl_balance(root->left) >= 0)
        return binary_tree_rotate_right(root);
    
    if (balance < -1 && avl_balance(root->right) <= 0)
        return binary_tree_rotate_left(root);
    
    if (balance > 1 && avl_balance(root->left) < 0)
    {
        root->left = binary_tree_rotate_left(root->left);
        return binary_tree_rotate_right(root);
    }

    if (balance < -1 && avl_balance(root->right) > 0)
    {
        root->right = binary_tree_rotate_right(root->right);
        return binary_tree_rotate_left(root);
    }

    return root;
}
