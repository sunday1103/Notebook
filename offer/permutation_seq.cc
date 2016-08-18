#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    int f(int n)
    {
        int r = 1;
        while (n)
        {
            r = r * n;
            n--;
        }
        return r;
    }

    char get(string s, int i, int a)
    {
        sort(s.begin(), s.end() - 1);
        return s[a];
    }
    string getPermutation(int n, int k)
    {
        string s;
        for (int i = 1; i <= n; i++)
        {
            s.push_back(i + '0');
        }
        s.push_back('\0');

        string rt;
        int a;
        int b;
        for (int i = 0; i < n; i++)
        {
            int tem = f(n - i - 1);
            b = k % tem;
            if (b == 0)
            {
                a = k / tem - 1;
                b = tem;
            }
            else
            {
                a = k / tem;
            }
            char cc = get(s, i, a);
            //cout << i << " -- " << cc << endl;
            rt.push_back(cc);
            s.erase(find(s.begin(), s.end(), cc));
            k = b;
        }
        return rt;
    }
};

int main()
{
    Solution S;
    int n;
    cin >> n;
    int k;
    cin >> k;
    cout << S.getPermutation(n, k) << endl;
}