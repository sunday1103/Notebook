#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.empty())
        {
            return true;
        }

        std::vector<int>::iterator p2 = popV.begin();
        std::vector<int>::iterator p1 = pushV.begin();
        stack<int> st;
        while (p2 != popV.end() && p1 != pushV.end())
        {
            if (*p1 != *p2)
            {
                st.push(*p1);
                p1++;
            }
            else
            {
                p1++;
                p2++;
                while (!st.empty() && st.top() == *p2)
                {
                    p2++;
                    st.pop();
                }
            }
        }

        if (p2 == popV.end() && p1 == pushV.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    std::vector<int> v(a, a + 5);
    int a1[5] = {4, 5, 3, 2, 1};
    std::vector<int> v1(a1, a1 + 5);

    Solution S;
    bool b = S.IsPopOrder(v, v1);
    cout << b << endl;
}