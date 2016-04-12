

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> n_return;
        int target1 = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            target1 = target - nums[i];
            for (int j = i + 1; j < size; j++)
            {
                if (nums[j] == target1)
                {
                    n_return.push_back(i);
                    n_return.push_back(j);
                    return n_return;
                }
            }
        }
    }
};

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mapping;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            mapping[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            const int gap = target - nums[i];
            if (mapping.find(gap) != mapping.end() && mapping[gap] > i)
            {
                result.push_back(i + 1);
                result.push_back(mapping[gap] + 1);
                break;
            }
        }
        return result;
    }
};
