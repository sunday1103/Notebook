#include <iostream>

using namespace std;

struct ListNode
{
    int n;
    ListNode *next;
    ListNode(int a) : n(a) {}
};

void dd(ListNode *root, ListNode *n)
{
    if (n->next == NULL)
    {
        for (ListNode *s = root; s != NULL; s = s->next)
        {
            if (s->next == n)
            {
                s->next = NULL;
                return;
            }
        }
    }

    n->n = n->next->n;
    n->next = n->next->next;
}

void print_list(ListNode *root)
{
    cout << "root -> ";
    for (ListNode *s = root->next; s != NULL; s = s->next)
    {
        cout << s->n << " -> ";
    }
    cout << "NULL" << endl;
}

int main()
{
    ListNode *root = new ListNode(0);
    int N;
    cin >> N;
    ListNode *pn = root;
    for (int i = 0; i < N; ++i)
    {
        int t;
        cin >> t;
        pn->next = new ListNode(t);
        pn = pn->next;
    }

    cout << "input is: ";
    print_list(root);

    int d1;
    cin >> d1;

    ListNode *search_node = NULL;

    for (ListNode *s = root; s != NULL; s = s->next)
    {
        if (s->n == d1)
        {
            search_node = s;
            break;
        }
    }

    dd(root, search_node);

    cout << "output is: ";
    print_list(root);
}