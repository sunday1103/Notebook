class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.count(nums[i]) == 0)
            {
                m[nums[i]] = 0;
            }
            else
            {
                m[nums[i]] += 1;
            }
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (m[nums[i]] == 1)
            {
                return nums[i];
            }
        }
        return 0;
    }
};

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (; i < nums.size() - 2;)
        {
            if (nums[i] == nums[i + 1])
            {
                i = i + 3;
            }
            else
            {
                return nums[i];
            }
        }

        if (i == nums.size() - 1)
        {
            return *(nums.end() - 1);
        }
        return 0;
    }
};

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            int c = 0;
            int d = 1 << i;
            for (int j = 0; j < nums.size(); ++j)
            {
                if (nums[j] & d)
                {
                    c++;
                }
            }

            if (c % 3)
            {
                ans |= d;
            }
        }
        return ans;
    }
};
