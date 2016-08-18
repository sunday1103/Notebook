#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*  错误代码
class Exchange
{
  public:
    int countWays(vector<int> changes, int n, int x)
    {
        sort(changes.begin(), changes.end());
        int min_change = changes[0];

        if (x < min_change)
        {
            return 0;
        }
        std::vector<int> log;
        log.resize(x, 0);
        log[min_change] = 1;

        for (int i = min_change + 1; i <= x; ++i)
        {
            for (int j = 0; j < changes.size(); ++j)
            {
                if (changes[j] < i)
                {
                    log[i] += log[i - changes[j]];
                }
            }
        }

        return log[x];
    }
};
*/

class Exchange1
{
  public:
    int countWays(vector<int> changes, int n, int x)
    {
        // 待兑换的金额是i，可用的范围是0-j-1
        // i = x,j = 0-n-1
        //int dp[x + 1][n];
        vector<vector<int> > dp;
        dp.resize(x + 1);
        for (int i = 0; i < x + 1; ++i)
        {
            dp[i].resize(n);
        }

        // 当待兑换的金额是0的时候，都是只有一种
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;
        // 第1列，待兑换的钱是i，因为只能用第一种零钱，所以只有当是第一种零钱的整数倍的时候，才有一种兑换方法
        for (int i = 1; i <= x; i++)
        {
            if (i % changes[0] == 0)
            {
                dp[i][0] = 1;
            }
        }
        //对于dp[i][j]，i是待兑换的钱数，j是changes[0-j]的钱币种类
        //dp[i][j] += dp[i][j-1],不用changes[j]这种钱
        //dp[i][j] += dp[i-changes[j]][j],用了一张changes[j]这种钱，剩下的待兑换的钱是i-changes[j]
        //只有以上两种可能
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (i - changes[j] >= 0)
                    dp[i][j] += (dp[i][j - 1] + dp[i - changes[j]][j]);
                else
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[x][n - 1];
    }
};

int main()
{
    int a[4] = {1, 2, 3, 5};
    std::vector<int> v(a, a + 4);

    Exchange1 E;
    for (int i = 0; i < 10; ++i)
    {
        cout << E.countWays(v, 4, i) << endl;
    }
}

/*
分析:
changes [1 2 3 5] for example
x = 1	count = 1	1
x = 2	count = 2	1+1 2
x = 3 	count = 3	1+1+1 2+1 3
x = 4 	count = 4 = f		1+1+1+1 = 4, 1+1+2 = 4, 1+3 = 4, 2+2 = 4
				  = 2 + 1 + 1
				  = 4
x = n	count = f(n)

x = n	count = f()
*/