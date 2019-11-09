#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Node *tree = TreeInsert(NULL, 5);

    int array[10] = {1, 5, 9, 4, 8, 7, 6, 2, 3, 0};
    for (size_t i = 0; i < 10; i++)
    {
        TreeInsert(tree, array[i]);
    }

    TreePrint(tree);
    tree = TreeDel(tree, 4);
    TreePrint(tree);
    tree = TreeDel(tree, 6);
    TreePrint(tree);
    tree = TreeDel(tree, 5);
    TreePrint(tree);
    tree = TreeDel(tree, 51);
    TreePrint(tree);
}