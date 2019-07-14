class Solution
{
  public:
    int flag;

    int TreeDepth(TreeNode *pRoot)
    {
        if (pRoot == NULL)
        {
            return 0;
        }
        int d1 = TreeDepth(pRoot->left) + 1;
        int d2 = TreeDepth(pRoot->right) + 1;

        if (d1 - d2 > 1 || d2 - d1 > 1)
        {
            flag = 0;
        }

        return d1 > d2 ? d1 : d2;
    }

    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (pRoot == NULL)
        {
            return 1;
        }

        flag = 1;
        TreeDepth(pRoot);
        return flag;
    }
};