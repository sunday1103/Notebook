#include "my_include.h"

class Solution
{
  public:
    bool IsContinuous(vector<int> numbers)
    {
        if (numbers.size() != 5)
        {
            return 0;
        }

        sort(numbers.begin(), numbers.end());

        if (numbers[3] == 0)
        {
            return 1;
        }

        if (numbers[2] == 0)
        {
            int sum = numbers[4] - numbers[3];

            if (sum == 0)
            {
                return 0;
            }

            if (sum <= 4)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if (numbers[1] == 0)
        {
            std::vector<int> v;
            v.resize(2);
            for (int i = 2; i < 4; ++i)
            {
                v[i - 2] = numbers[i + 1] - numbers[i];
            }

            int sum = 0;
            for (int i = 0; i < 2; ++i)
            {
                if (v[i] == 0)
                {
                    return 0;
                }
                else if (v[i] > 1)
                {
                    sum += v[i] - 1;
                }
            }

            if (sum <= 2)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if (numbers[0] == 0)
        {
            std::vector<int> v;
            v.resize(3);
            for (int i = 1; i < 4; ++i)
            {
                v[i - 1] = numbers[i + 1] - numbers[i];
            }

            int sum = 0;
            for (int i = 0; i < 3; ++i)
            {
                if (v[i] == 0)
                {
                    return 0;
                }
                else if (v[i] > 1)
                {
                    sum += v[i] - 1;
                }
            }

            if (sum <= 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            if (numbers[i] + 1 != numbers[i + 1])
            {
                return 0;
            }
        }

        return 1;
    }
};

class Solution
{
  public:
    bool IsContinuous(vector<int> numbers)
    {

        if (numbers.size() != 5)
        {
            return 0;
        }

        sort(numbers.begin(), numbers.end());
        int i0 = 0;
        while (numbers[i0++] == 0)
            ;
        int num = i0 - 1;

        std::vector<int> v(14, 0);

        for (int i = i0 - 1; i < 5; ++i)
        {
            if (v[numbers[i]] != 0)
            {
                return 0;
            }

            v[numbers[i]] = numbers[i];
        }

        int count = 0;
        for (int i = numbers[i0 - 1]; i < numbers[4]; ++i)
        {
            if (v[i] == 0)
            {
                count++;
            }
        }

        if (count <= num)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Solution S;
    int a[5] = {0, 0, 4, 6, 4};
    std::vector<int> v(a, a + 5);
    cout << S.IsContinuous(v) << endl;
}