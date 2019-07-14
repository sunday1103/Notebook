
class Solution
{
  public:
    int GetNumberOfK(vector<int> data, int k)
    {
        vector<int>::iterator it1 = lower_bound(data.begin(), data.end(), k);
        vector<int>::iterator it2 = upper_bound(data.begin(), data.end(), k);

        if (it1 != data.end())
        {
            return it2 - it1;
        }
        else
        {
            return 0;
        }
    }
};

class Solution
{
  public:
    int f1(vector<int> data, int k)
    {
        int lo = 0;
        int hi = data.size() - 1;
        int mid = (lo + hi) / 2;

        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (data[mid] < k)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return lo; // 第一个>=k的位置。
                   //return hi ;// 第一个 小于k的位置
    }

    int f2(vector<int> data, int k)
    {
        int lo = 0;
        int hi = data.size() - 1;
        int mid = (lo + hi) / 2;

        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (data[mid] <= k)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return hi; // 第一个小于等于k的位置。
                   //return lo; // 第一个大于k的位置
    }

    int GetNumberOfK(vector<int> data, int k)
    {
        int lo = f1(data, k);
        int hi = f2(data, k);

        return hi - lo + 1;
    }
};