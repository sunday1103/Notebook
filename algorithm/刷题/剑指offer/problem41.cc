#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        int i = 0;
        std::vector<int> v;
        std::vector<int> v1;
        v.resize(2);
        if (array.size() < 2)
        {
            return v1;
        }

        while (array[i] <= sum / 2 && i < array.size())
        {
            if (binary_search(array.begin() + i + 1, array.end(), sum - array[i]))
            {
                std::vector<int>::iterator it2 = upper_bound(array.begin() + i + 1, array.end(), sum - array[i]);
                v[0] = array[i];
                v[1] = *(it2 - 1);
                return v;
            }
            i++;
        }
        return v1;
    }
};

class Solution
{
  public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        std::vector<int> v;
        std::vector<int> v1;
        v.resize(2);
        if (array.size() < 2)
        {
            return v1;
        }

        int i = 0;
        int j = array.size() - 1;
        while (i != j)
        {
            if (array[i] + array[j] == sum)
            {
                v[0] = array[i];
                v[1] = array[j];
                return v;
            }
            else if (array[i] + array[j] > sum)
            {
                j = j - 1;
            }
            else
            {
                i = i + 1;
            }
        }
        return v1;
    }
};

ostream &operator<<(ostream &o, std::vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        o << v[i] << " ";
    }
    return o;
}

int main()
{
    Solution S;
    int a[] = {1, 2, 4, 7, 11, 15};
    std::vector<int> v(a, a + 6);
    int N;
    cin >> N;
    cout << S.FindNumbersWithSum(v, N) << endl;
}