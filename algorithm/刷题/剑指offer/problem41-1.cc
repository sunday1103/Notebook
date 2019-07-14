#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    int myf(double a, double b) { return (a + b) / 2 * (b - a + 1); }

    vector<vector<int> > FindContinuousSequence(int sum)
    {
        vector<vector<int> > v;
        if (sum < 3)
        {
            return v;
        }

        int i = 1;
        int j = 2;

        while (j != sum)
        {
            if (myf(i, j) == sum)
            {
                std::vector<int> v1;
                for (int k = i; k <= j; ++k)
                {
                    v1.push_back(k);
                }
                v.push_back(v1);
                j++;
            }
            else if (myf(i, j) < sum)
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return v;
    }
};

ostream &operator<<(ostream &o, std::vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        o << v[i] << " ";
    }
    return o;
}

int main()
{
    Solution S;
    int N;
    cin >> N;
    vector<vector<int> > v = S.FindContinuousSequence(N);
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }
    // cout << S.FindContinuousSequence(N) << endl;
}