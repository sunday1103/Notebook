#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000

struct node
{
    int id;
    node *p;
    int re; // relation with the parent of whole set // 0: same; 1: x eat p 2: p is eat by p
    int rank;
    node(int id_) : id(id_) {}
};

int make_set(node *x)
{
    x->p = x;
    x->re = 0;
    x->rank = 0;
    return 0;
}

int get_re(node *x)
{
    if (x->p == x)
        return 0;
    else
    {
        return (get_re(x->p) + x->re) % 3;
        // if (x->re == 0)
        // return get_re(x->p);
        // else if (x->re = 1)
        // return (get_re(x->p) + 1) % 3;
        // else
        // return (get_re(x->p) + 2) % 3;
    }
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

int link(node *x, node *y, int s)
{
    if (x->rank < y->rank)
    {
        x->p = y;
        if (s == 0)
            x->re = 0;
        else
            x->re = 1;
    }
    else
    {
        y->p = x;
        if (s == 0)
            y->re = 0;
        else
            y->re = 2;
        if (x->rank == y->rank)
        {
            x->rank = x->rank + 1;
        }
    }
}

int unit1(node *x, node *y)
{
    int b = 0;
    link(find_set(x), find_set(y), b);
    return 0;
}

int unit2(node *x, node *y)
{
    int b = 1;
    link(find_set(x), find_set(y), b);
    return 0;
}

int main()
{
    int num = 0;
    int N;
    int K;
    cin >> N >> K;
    std::vector<node *> v;
    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        //node *n = ;
        node *np = new node(i);
        v[i] = np;
        make_set(np);
    }
    for (int i = 0; i < K; i++)
    {
        int AD;
        int x;
        int y;
        cin >> AD;
        cin >> x >> y;
        if (x >= N || y >= N)
            num++;
        else if (x == y)
            num++;
        else if (AD == 1)
        {
            if (find_set(v[x]) != find_set(v[y]))
            {
                unit1(v[x], v[y]);
            }
            else if (get_re(v[x]) != get_re(v[y]))
            {
                num++;
            }
        }
        else if (AD == 2)
        {
            if (find_set(v[x]) != find_set(v[y]))
            {
                unit2(v[x], v[y]);
            }
            else
            {
                if (get_re(v[x]) == 0)
                {
                    if (get_re(v[y]) != 2)
                        num++;
                }
                else if (get_re(v[x]) == 1)
                {
                    if (get_re(v[y]) != 0)
                        num++;
                }
                else
                {
                    if (get_re(v[y]) != 1)
                        num++;
                }
            }
        }
    }
    cout << "num " << num << endl;
}
