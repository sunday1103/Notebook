#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 最大路径和分为2种情况，
// 情况1： 经过root，
// 情况2： 不经过root，那么最大路径和就是左子树和右子树的最大路径和的最大值；
// 综合情况1和情况2，root的最大路径和就是（root最大左深度+root最大右深度+root， 左子树的最大路径和， 右子树的最大路径和） 三者的最大值。
int maxPathSumHelper(struct TreeNode *root, int *result) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return root->val;
    }

    int leftMax = maxPathSumHelper(root->left, result);
    leftMax = MAX(leftMax, 0);
    int rightMax = maxPathSumHelper(root->right, result);
    rightMax = MAX(rightMax, 0);
    int midMax = MAX(leftMax, rightMax) + root->val;
    int resultTmp = leftMax + rightMax + root->val;

    if (resultTmp > *result) {
        *result = resultTmp;
    }

    return midMax;
}

int maxPathSum(struct TreeNode *root) {
    int result = root->val;
    maxPathSumHelper(root, &result);
    return result;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
