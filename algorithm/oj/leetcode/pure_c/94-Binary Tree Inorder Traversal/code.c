#include "stdlib.h"

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAX_NUM 10000

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int *returnArray = (int*)malloc(sizeof(int)*MAX_NUM);
    *returnSize = 0;
    
    struct TreeNode* s[MAX_NUM] = {root};
    int top = 1;

    while(top > 0) {
        struct TreeNode *topNode = s[top - 1];
        if (topNode->left == NULL)
        {
            returnArray[(*returnSize)++] = topNode->val;
            top = top - 1;
            if (topNode->right != NULL)
            {
                s[top++] = topNode->right;
            }
            continue;
        }
        
        s[top++] = topNode->left;
        continue;
    }
}