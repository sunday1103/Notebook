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
    vector<vector<int> > FindPath(TreeNode *root, int expectNumber)
    {
        vector<vector<int> > v;
        if (root == NULL)
        {
            return v;
        }

        if (root->val > expectNumber)
        {
            return v;
        }

        if (root->left == NULL && root->right == NULL)
        {
            if (root->val == expectNumber)
            {
                std::vector<int> temp;
                temp.push_back(root->val);
                v.push_back(temp);
                return v;
            }
        }

        vector<vector<int> > v_left;
        vector<vector<int> > v_right;

        v_left = FindPath(root->left, expectNumber - root->val);
        v_right = FindPath(root->right, expectNumber - root->val);

        for (int i = 0; i < v_left.size(); ++i)
        {
            std::vector<int> temp1;
            temp1.push_back(root->val);
            temp1.insert(temp1.end(), v_left[i].begin(), v_left[i].end());
            v.push_back(temp1);
        }

        for (int i = 0; i < v_right.size(); ++i)
        {
            std::vector<int> temp1;
            temp1.push_back(root->val);
            temp1.insert(temp1.end(), v_right[i].begin(), v_right[i].end());
            v.push_back(temp1);
        }

        return v;
    }
};