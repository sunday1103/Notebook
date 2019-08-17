/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution
{
  public:
    int TreeDepth(TreeNode *pRoot)
    {
        if (pRoot == NULL)
        {
            return 0;
        }
        int d1 = TreeDepth(pRoot->left) + 1;
        int d2 = TreeDepth(pRoot->right) + 1;

        return d1 > d2 ? d1 : d2;
    }
};

class Solution
{
  public:
    int TreeDepth(TreeNode *pRoot)
    {
    }
};
