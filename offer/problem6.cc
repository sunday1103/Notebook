/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ostream& operator<<(ostream& o, std::vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    o << v[i] << " ";
  }
  return o;
}

class Solution {
 public:
  struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
    TreeNode* root = NULL;
    if (pre.size() == 0) {
      return root;
    }
    root = new TreeNode(pre[0]);

    std::vector<int> left_pre;
    std::vector<int> left_in;
    std::vector<int> right_pre;
    std::vector<int> right_in;
    std::vector<int>::iterator it = std::find(in.begin(), in.end(), pre[0]);
    cout << "find in it *it = " << *it << endl;
    int left_size = it - in.begin();
    int right_size = in.end() - it - 1;

    cout << pre << " -- " << in << endl;
    cout << "left_size " << left_size << "  right_size " << right_size << endl;

    left_pre.resize(left_size);
    left_in.resize(left_size);
    right_pre.resize(right_size);
    right_in.resize(right_size);

    cout << "copying..." << endl;
    copy(in.begin(), it, left_in.begin());
    cout << "left_in - " << left_in << endl;
    copy(it + 1, in.end(), right_in.begin());
    cout << "right_in - " << right_in << endl;
    copy(pre.begin() + 1, pre.begin() + 1 + left_size, left_pre.begin());
    cout << "left_pre - " << left_pre << endl;
    copy(pre.begin() + 1 + left_size, pre.end(), right_pre.begin());
    cout << "right_pre - " << right_pre << endl;

    cout << "copy sucess" << endl;

    root->left = reConstructBinaryTree(left_pre, left_in);
    root->right = reConstructBinaryTree(right_pre, right_in);

    return root;
  }
};

int main() {
  std::vector<int> pre;
  std::vector<int> in;
  int a = 0;
  int N = 0;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> a;
    pre.push_back(a);
  }
  for (int i = 0; i < N; ++i) {
    cin >> a;
    in.push_back(a);
  }
  Solution S;
  S.reConstructBinaryTree(pre, in);
}