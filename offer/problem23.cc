/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

#include <queue>

class Solution
{
  public:
    inline void do_something(vector<int> &v, TreeNode *n)
    {
        v.push_back(n->val);
    }
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        std::vector<int> v;
        if (root == NULL)
        {
            return v;
        }
        queue<TreeNode *> q;
        //queue<int> q2;

        do_something(v, root);
        q.push(root);

        while (!q.empty())
        {
            int num = q.size();
            TreeNode *t = NULL;
            for (int i = 0; i < num; i++)
            {
                t = q.front();
                q.pop();
                if (t->left != NULL)
                {
                    do_something(v, t->left);
                    q.push(t->left);
                }
                if (t->right != NULL)
                {
                    do_something(v, t->right);
                    q.push(t->right);
                }
            }
        }
    }
};