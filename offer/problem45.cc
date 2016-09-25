#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    std::vector<int> v;
    std::vector<int> num;
    int myf(int n, int m, int s)
    {
        if (n == 1)
        {
            return num[s % n];
        }
        int m1 = (m - 1) % n;
        int s1 = (s + m1) % n;
        v.push_back(num[s1]);

        num.erase(num.begin() + s1);
        return myf(n - 1, m, s1);
    }
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if (n == 0)
        {
            return -1;
        }

        for (int i = 0; i < n; ++i)
        {
            num.push_back(i);
        }
        return myf(n, m, 0);
    }
};

int main()
{
    Solution S;
    cout << S.LastRemaining_Solution(5, 2) << endl;
}