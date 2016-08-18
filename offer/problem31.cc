class Solution
{
  public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if (array.empty())
            return 0;
        int max_sum = array[0];
        int sum = array[0];

        if (array.size() == 1)
            return array[0];

        for (int i = 1; i < array.size(); i++)
        {
            if (array[i] > 0)
            {
                if (sum > 0)
                {
                    sum += array[i];
                    if (sum > max_sum)
                    {
                        max_sum = sum;
                    }
                }
                else
                {
                    sum = array[i];
                    if (sum > max_sum)
                    {
                        max_sum = sum;
                    }
                }
            }
            else
            {
                if (sum + array[i] > 0)
                {
                    sum += array[i];
                }
                else
                {
                    sum = array[i];
                    if (max_sum < array[i])
                    {
                        max_sum = array[i];
                    }
                }
            }
        }
        return max_sum;
    }
};

class Solution
{
  public:
    int maxSubArray(vector<int> array)
    {
        if (array.empty())
            return 0;
        int max_sum = array[0];
        int sum = array[0];

        if (array.size() == 1)
            return array[0];

        for (int i = 1; i < array.size(); i++)
        {
            if (sum < 0)
                sum = array[i];
            else
                sum += array[i];

            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }
        return max_sum;
    }
};
