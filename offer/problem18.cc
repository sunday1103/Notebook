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
    bool is_contain(TreeNode *p1, TreeNode *p2)
    {
        if (p2 == NULL)
        {
            return true;
        }

        if (p1 == NULL)
        {
            return false;
        }

        if (p1->val != p2->val)
        {
            return false;
        }

        if (is_contain(p1->left, p2->left) && is_contain(p1->right, p2->right))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool f1(TreeNode *p, TreeNode *p0)
    {
        if (p == NULL)
        {
            return false;
        }

        if (p->val == p0->val)
        {
            if (is_contain(p, p0))
                return true;
        }

        if (f1(p->left, p0) || f1(p->right, p0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot2 == NULL)
        {
            return false;
        }

        return f1(pRoot1, pRoot2);
    }
};