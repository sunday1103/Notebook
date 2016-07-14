#include <iostream>
#include <vector>
#include <stack>

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
	void pre_t_1();
	void in_t_1();
	void post_t_1();
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

int BSTtree::insert(node *n)
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
    return 0;
}

void BSTtree::do_something(node *n)
{
    cout << n->key << endl;
}

void BSTtree::pre_t()
{
    pre_t(root);
}

void BSTtree::pre_t_1()
{
	pre_t_1(root);
}

void BSTtree::in_t()
{
    in_t(root);
}

void BSTtree::post_t()
{
    post_t(root);
}

void BSTtree::in_t_1()
{
	in_t_1(root);
}

void BSTtree::post_t_1()
{
	post_t_1(root);
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
	/* 构建栈来遍历
    if (n == NULL)
        return;
	stack<node *> st;
	st.push(n);
	while (!st.empty())
	{
		node *n1 = st.top();
		do_something(n1);
		st.pop();
		if (n1->right != NULL) st.push(n1->right);
		if (n1->left != NULL) st.push(n1->left);
	}
	*/

	/*不用构建栈*/
	if (n == NULL)
		return; 
	node *n1 = n->left;
	node *nn = n;
	while (nn != NULL)
	{
		do_something(n);
		while (nn->left != NULL)
		{
			do_something(nn->left);
			node *nr = nn->right;
			node *nrp = nn;
			while (nr != NULL)
			{
				nrp = nr;
				nr = nr->right;
			}
			nrp->right = nn;
			nn = nn->left;
		}
		nn = nn->right;
	}
}

void BSTtree::in_t_1(node *n)
{
    if (n == NULL)
        return;
	stack<node *> st;
	node * nn = n;
	while (nn!=NULL || !st.empty())
	{
		while (nn != NULL)
		{
			st.push(nn);
			nn = nn->left;
		}
		nn = st.top();
		st.pop();
		do_something(nn);
		nn = nn->right;
	}
}

void BSTtree::post_t_1(node *n)
{
    if (n == NULL)
        return;
	node *nn = n;
	stack<node *> st;
	node *nnext = NULL;
	while (!st.empty() || nn != NULL);
	{
		while (nn != NULL)
		{
			st.push(nn);
		//	if (nn->right != NULL)
	//			st.push(nn->right);
			if (nn->left == NULL) break;
			nnext = nn->right;
			nn = nn->left;
		}
		//nn = st.top();
		if (nn->right != NULL)
		{
			nn = nn->right;
		}
		else
		{
			do_something(nn);
			st.pop();
			nn = nnext;
		}
	}
}

int main()
{
    vector<int> v;
    int a;
    while (cin >> a)
        v.push_back(a);
    BSTtree BST(v);
    cout << "pre-----------" << endl;
    BST.pre_t();
	//cout << "pre_1----------" << endl;
	//BST.pre_t_1();
    cout << "in=======" << endl;
    BST.in_t();
	cout << "in_1=======" << endl;
	BST.in_t_1();
    cout << "post+++++++++++++++" << endl;
    BST.post_t();
	cout << "post_1++++++++++++++" << endl;
	BST.post_t_1();
	//system("pause");
}
