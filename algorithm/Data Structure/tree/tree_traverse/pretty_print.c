#include "../bstree/bstree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
        2
       / \
      /   \
     /     \
    1       3
   / \     / \
  0   7   9   1
 /   / \     / \
2   1   0   8   8
       /
      7                   5 
                         / \
                        /   \
                       /     \
                      /       \
                     /         \
                    1           9
                   / \         /
                  0   4       8
                     /       / 
                    2       7
                     \     /
                      3   6                 

*/

#define MAX_NODE_NUM 100
void Tree_Get_Offset(Node *root);

void Tree_Get_maxRight(Node *root, int offset, int *maxRight)
{
    if (root == NULL)
    {
        if (*maxRight < offset)
        {
            *maxRight = offset;
        }
        
        return;
    }

    Tree_Get_Offset(root);

    Tree_Get_maxRight(root->right, offset + root->offset, maxRight);
    Tree_Get_maxRight(root->left, offset - root->offset, maxRight);
}

void Tree_Get_maxLeft(Node *root, int offset, int *maxLeft)
{
    if (root == NULL)
    {
        if (*maxLeft > offset)
        {
            *maxLeft = offset;
        }
        
        return;
    }

    Tree_Get_Offset(root);

    Tree_Get_maxLeft(root->right, offset + 1, maxLeft);
    Tree_Get_maxLeft(root->left, offset - 1, maxLeft);
}

void Tree_Get_Offset(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    int leftOffset = 0;
    Tree_Get_maxRight(root->left, 0, &leftOffset);
    int rightOffset = 0;
    Tree_Get_maxLeft(root->right, 0, &rightOffset);
    root->offset = leftOffset - rightOffset + 1;
}

void Tree_Get_Location(Node *root, int loc)
{
    if (root == NULL)
    {
        return;
    }

    root->location = loc;

    Tree_Get_Location(root->left, 0 - root->offset);
    Tree_Get_Location(root->right, root->offset);
}

void Tree_Offset_Print(Node *root)
{
    int queueNum = 1;
    Node* queue[MAX_NODE_NUM];
    queue[0] = root;

    int queueNumNext = 0;
    Node* queueNext[MAX_NODE_NUM];

    while (queueNum != 0)
    {
        int printNum = 0;
        int loc = 0;
        while(printNum != queueNum)
        {
            if (queue[printNum]->location == loc)
            {
                printf("%d", queue[printNum]->key);
                printNum++;
            }
            loc++;
        }
        printf("\n");

        queueNumNext = 0;
        for (size_t i = 0; i < queueNum; i++)
        {
            if (queue[i]->left != NULL)
            {
                queueNext[queueNumNext] = queue[i]->left;
                queueNumNext++;
            }
            
            if (queue[i]->right != NULL)
            {
                queueNext[queueNumNext] = queue[i]->right;
                queueNumNext++;
            }
        }

        queueNum = queueNumNext;
        memcpy(queue, queueNext, queueNum * sizeof(Node*));
    }
}

void Tree_Pretty_Print(Node *root)
{
    Tree_Get_Offset(root);
    int maxOffset = 0;
    Tree_Get_maxLeft(root, 0, &maxOffset);
    Tree_Get_Location(root, maxOffset);
    Tree_Offset_Print(root);
}


int main()
{
    Node *tree = TreeInsert(NULL, 5);

    int array[10] = {1, 5, 9, 4, 8, 7, 6, 2, 3, 0};
    for (size_t i = 0; i < 10; i++)
    {
        TreeInsert(tree, array[i]);
    }

    TreePrint(tree);
    Tree_Pretty_Print(tree);

    tree = TreeDel(tree, 4);
    TreePrint(tree);
    tree = TreeDel(tree, 6);
    TreePrint(tree);
    tree = TreeDel(tree, 5);
    TreePrint(tree);
    tree = TreeDel(tree, 51);
    TreePrint(tree);
}