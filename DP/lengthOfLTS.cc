class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int n = nums.size();
        int dp[n];
        //memset(&dp, 1, n); its wrong to set dp to 1, using memset. Attention
        for (int i = 0; i < n; ++i)
        {
            dp[i] = 1;
        }

        int re = 1;
        for (int i = 1; i < n; ++i)
        {
            int max_length = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] > nums[j])
                {
                    if (max_length < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        max_length = dp[i];
                    }
                }
            }

            if (re < max_length)
            {
                re = max_length;
            }
        }

        return re;
    }
};

/*
analyse
状态：
dp[i]: 以i结尾的最长递增子串


复杂度分析
第一个循环n次
第二个循环j次
共 1 + 2 +3 +。。+n次 O(n^2)


*/