#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Type;

typedef struct NodeStruct
{
    Type key;
    struct NodeStruct *parent;
    struct NodeStruct *left;
    struct NodeStruct *right;
}Node;

void TreePrint(Node *root);
void TreeFree(Node *root);
Node *TreeFind(Node *root, Type key);
Node *TreeFindMin(Node *root);
Node *TreeFindMax(Node *root);
Node *TreeInsert(Node *root, Type key);
Node *TreeDel(Node *root, Type key);

Node *TreeInsert(Node *root, Type key)
{
    if (root == NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (root->key >= key)
    {
        root->left = TreeInsert(root->left, key);
        return root;
    }

    if (root->key < key)
    {
        root->right = TreeInsert(root->right, key);
        return root;
    }
    
    return NULL;
}

void TreePrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("\t%d\n\t", root->key);
    TreePrint(root->left);
    TreePrint(root->right);
}

int main()
{
    Node tree;
    tree.key = 5;
    tree.left = NULL;
    tree.right = NULL;
    TreeInsert(&tree, 3);
    TreeInsert(&tree, 1);
    TreeInsert(&tree, 6);
    TreeInsert(&tree, 9);
    TreeInsert(&tree, 4);
    TreePrint(&tree);
}