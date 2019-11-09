#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

Node *TreeInsert(Node *root, Type key)
{
    if (root == NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
    }

    if (root->key > key)
    {
        root->left = TreeInsert(root->left, key);
    }
    else if (root->key < key)
    {
        root->right = TreeInsert(root->right, key);
    }
    else
    {
        // do nothing
    }

    return root;
}

Node *TreeFind(Node *root, Type key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->key == key)
    {
        return root;
    }
    else if (root->key > key)
    {
        return TreeFind(root->left, key);
    }
    else
    {
        return TreeFind(root->right, key);
    }
}

Node *TreeFindMax(Node *root)
{
    if (root->right == NULL)
    {
        return root;
    }

    return TreeFindMax(root->right);
}

Node *TreeFindMin(Node *root)
{
    if (root->left == NULL)
    {
        return root;
    }

    return TreeFindMin(root->left);
}

Node *TreeDel(Node *root, Type key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->key < key)
    {
        root->right = TreeDel(root->right, key);
        return root;
    }

    if (root->key > key)
    {
        root->left = TreeDel(root->left, key);
        return root;
    }

    if (root->left != NULL && root->right != NULL)
    {
        Node *maxNodeRight = TreeFindMin(root->right);
        root->key = maxNodeRight->key;
        root->right = TreeDel(root->right, maxNodeRight->key);
        return root;
    }
    else
    {
        Node *temp = root;
        if (root->left != NULL)
        {
            root = root->left;
        }
        else if (root->right != NULL)
        {
            root = root->right;
        }
        else
        {
            root = NULL;
        }

        free(temp);
        return root;
    }
}

void TreePrintByLevel(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    for (size_t i = 0; i < level; i++)
    {
        printf("  ");
    }
    printf("%d\n", root->key);
    TreePrintByLevel(root->left, level + 1);
    TreePrintByLevel(root->right, level + 1);
}

void TreePrint(Node *root)
{
    printf("begin: ---\n");
    TreePrintByLevel(root, 0);
    printf("end: -----\n");
}