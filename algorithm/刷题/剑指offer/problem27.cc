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
    vector<TreeNode *> myf(TreeNode *n)
    {
        TreeNode *h = NULL;
        TreeNode *t = NULL;
        std::vector<TreeNode *> v;
        v.push_back(h);
        v.push_back(t);

        if (n == NULL)
        {
            return v;
        }

        if (n->left == NULL && n->right == NULL)
        {
            v[0] = n;
            v[1] = n;
            return v;
        }

        if (n->right != NULL)
        {
            vector<TreeNode *> v_right = myf(n->right);
            n->right = v_right[0];
            (v_right[0])->left = n;

            v[1] = v_right[1];
            if (n->left == NULL)
            {
                v[0] = n;
            }
        }

        if (n->left != NULL)
        {
            vector<TreeNode *> v_left = myf(n->left);
            n->left = v_left[1];
            (v_left[1])->right = n;

            v[0] = v_left[0];
            if (n->right == NULL)
            {
                v[1] = n;
            }
        }

        return v;
    }

    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        std::vector<TreeNode *> v;
        v = myf(pRootOfTree);
        return v[0];
    }
};