
原始版本
---------
暴力复杂度 O(1+2+3+..+n)
```cpp
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
```
使用哈希表 - from 灵魂机器
-----
**采用unordered_map**
1. 先用一个unordered_map 储存所有元素，
2. 然后利用map自带的find函数快速的找到是否有相应值
```cpp
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
                result.push_back(i);
                result.push_back(mapping[gap]);
                break;
            }
        }
        return result;
    }
};
```
