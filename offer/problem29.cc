#include <unodered_map>

class Solution
{
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        unodered_map<int, int> um;
        for (int i = 0; i < numbers.size(); ++i)
        {
            um[numbers[i]] = um[numbers[i]] + 1;
            if (um[numbers[i]] > numbers.size() / 2)
            {
                return numbers[i];
            }
        }
        return 0;
    }
};