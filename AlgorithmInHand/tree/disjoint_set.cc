#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000

struct node
{
    int id;
    node *p;
    bool re; // relation with the parent of whole set
    int rank;
    node(int id_) : id(id_) {}
};

int make_set(node *x)
{
    x->p = x;
    x->re = true;
    x->rank = 0;
    return 0;
}

bool get_re(node *x)
{
    if (x->p == x)
        return 1;
    else
        return x->re == 1 ? get_re(x->p) : !get_re(x->p);
}

node *find_set(node *x)
{
    if (x->p != x)
    {
        x->re = get_re(x);
        x->p = find_set(x->p);
    }
    return x->p;
}

int link(node *x, node *y, bool s)
{
    if (x->rank < y->rank)
    {
        x->p = y;
        if (s)
            x->re = 1;
        else
            x->re = 0;
    }
    else
    {
        y->p = x;
        if (s)
            y->re = 1;
        else
            y->re = 0;
        if (x->rank == y->rank)
        {
            x->rank = x->rank + 1;
        }
    }
}

int unit(node *x, node *y)
{
    bool b = get_re(x) ^ get_re(y);
    link(find_set(x), find_set(y), b);
    return 0;
}

int main()
{
    int N;
    cin >> N;
    std::vector<node *> v;
    v.resize(MAX);
    for (int i = 0; i < MAX; i++)
    {
        //node *n = ;
        node *np = new node(i);
        v[i] = np;
        make_set(np);
    }
    for (int i = 0; i < N; i++)
    {
        char AD;
        int x;
        int y;
        cin >> AD;
        cin >> x >> y;
        if (AD == 'A')
        {
            if (find_set(v[x]) != find_set(v[y]))
            {
                cout << "Not sure yet" << endl;
            }
            else if (get_re(v[x]) == get_re(v[y]))
            {
                cout << "In the same gang" << endl;
            }
            else
            {
                cout << "In different gangs" << endl;
            }
        }
        else if (AD == 'D')
        {
            unit(v[x], v[y]);
        }
    }
}
