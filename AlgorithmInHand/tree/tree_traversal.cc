#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int key;
    node *parent;
    node *left;
    node *right;
    node(int n) { key = n; }
};

class BSTtree
{
  private:
    node *root;

  public:
    int insert(node *n);
    void pre_t(node *n);
    void in_t(node *n);
    void post_t(node *n);
    void pre_t_1(node *n);
    void in_t_1(node *n);
    void post_t_1(node *n);
    void pre_t();
    void in_t();
    void post_t();
    int delete_node(node *n);
    void do_something(node *n);
    BSTtree(vector<int> &v);
    BSTtree();
};

BSTtree::BSTtree()
{
    root = NULL;
}

BSTtree::BSTtree(vector<int> &v)
{
    root = NULL;
    for (int i = 0; i < v.size(); i++)
    {
        node *n = new node(v[i]);
        insert(n);
    }
}

BSTtree::insert(node *n)
{
    if (root == NULL)
    {
        root = n;
        root->parent = NULL;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        node *p, *x = root;
        p = NULL;
        while (x != NULL)
        {
            p = x;
            if (n->key < p->key)
                x = x->left;
            else
                x = x->right;
        }
        n->parent = p;
        if (n->key < p->key)
            p->left = n;
        else
            p->right = n;
        n->left = NULL;
        n->right = NULL;
    }
}

void BSTtree::do_something(node *n)
{
    cout << n->key << endl;
}

void BSTtree::pre_t()
{
    pre_t(root);
}

void BSTtree::in_t()
{
    in_t(root);
}

void BSTtree::post_t()
{
    post_t(root);
}

void BSTtree::pre_t(node *n)
{
    if (n == NULL)
        return;

    do_something(n);
    pre_t(n->left);
    pre_t(n->right);
}

void BSTtree::in_t(node *n)
{
    if (n == NULL)
        return;

    in_t(n->left);
    do_something(n);
    in_t(n->right);
}

void BSTtree::post_t(node *n)
{
    if (n == NULL)
        return;

    in_t(n->left);
    in_t(n->right);
    do_something(n);
}

void BSTtree::pre_t_1(node *n)
{
    if (n == NULL)
        return;

    do_something(n);
    pre_t(n->left);
    pre_t(n->right);
}

void BSTtree::in_t_1(node *n)
{
    if (n == NULL)
        return;

    in_t(n->left);
    do_something(n);
    in_t(n->right);
}

void BSTtree::post_t_1(node *n)
{
    if (n == NULL)
        return;

    in_t(n->left);
    in_t(n->right);
    do_something(n);
}

int main()
{
    vector<int> v;
    int a;
    while (cin >> a)
        v.push_back(a);
    BSTtree BST(v);
    cout << "pre" << endl;
    BST.pre_t();
    cout << "in" << endl;
    BST.in_t();
    cout << "post" << endl;
    BST.post_t();
}
