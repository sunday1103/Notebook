#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &o, std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        o << v[i] << " ";
    }
    return o;
}

class Solution
{
  public:
    void m_fill(vector<vector<int> > &rt, vector<int> &v, int val, int index, int n, int k)
    {
        if (index == k - 1)
        {
            v[index] = val;
            rt.push_back(v);
            //cout << v << endl;
            return;
        }

        v[index] = val;

        for (int i = val + 1; i <= n; i++)
        {
            m_fill(rt, v, i, index + 1, n, k);
        }
    }

    vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > rt;

        vector<int> vv;
        vv.resize(k);
        int index = 0;

        for (int i = 1; i <= n; i++)
        {
            m_fill(rt, vv, i, index, n, k);
        }

        //cout << rt.size() << endl;
        //for (int i = 0; i < rt.size(); ++i)
        //{
        //    cout << rt[i] << endl;
        //}
        return rt;
    }
};

class Solution1
{
  public:
    vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > rt;

        vector<int> vv;
        // vv.resize(k);

        std::vector<int> bb;
        bb.resize(n);
        int a = k;
        while (a)
        {
            bb[n - a] = 1;
            a = a - 1;
        }

        std::vector<int> num;
        for (int i = 1; i <= n; ++i)
        {
            num.push_back(i);
        }

        do
        {
            for (int i = 0; i < n; ++i)
            {
                if (bb[i])
                {
                    vv.push_back(num[i]);
                }
            }
            rt.push_back(vv);
            vv.resize(0);
        } while (next_permutation(bb.begin(), bb.end()));

        // cout << rt.size() << endl;
        // for (int i = 0; i < rt.size(); ++i)
        // {
        //     cout << rt[i] << endl;
        // }
        return rt;
    }
};

int main()
{
    Solution1 S;
    int n;
    cin >> n;
    int k;
    cin >> k;
    S.combine(n, k);
}