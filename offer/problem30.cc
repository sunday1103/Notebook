
// sort method
class Solution
{
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        std::vector<int> v;

        if (input.empty())
            return v;

        if (k > input.size())
            return v;

        v.resize(k);
        sort(input.begin(), input.end());
        copy(input.begin(), input.begin() + k, v.begin());
        return v;
    }
};

//  using nth_element

class Solution
{
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        std::vector<int> v;

        if (input.empty())
            return v;

        if (k > input.size())
            return v;

        v.resize(k);
        nth_element(input.begin(), input.begin() + k, input.end());
        copy(input.begin(), input.begin() + k, v.begin());
        return v;
    }
};

// using partial_sort

class Solution
{
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        std::vector<int> v;

        if (input.empty())
            return v;

        if (k > input.size())
            return v;

        v.resize(k);
        partial_sort(input.begin(), input.begin() + k, input.end());
        copy(input.begin(), input.begin() + k, v.begin());
        return v;
    }
};

// partition

class myisgreater
{
  public:
    int val;
    myisgreater(int aa) : val(aa) {}
    bool operator()(int a)
    {
        if (a < val)
            return 1;
        else
            return 0;
    }
};

class Solution
{
  public:
    void myf(std::vector<int> v, std::vector<int> input, int k, int n1_n, int n2_n)
    {
        auto n1 = input.begin() + n1_n;
        auto n2 = input.begin() + n2_n;
        myisgreater is1(*n1);
        auto it = partition(n1, n2, is1);
        if (it - n1 == k - 1)
        {
            for (int i = n1_n + 0; i <= n1_n + k; ++i)
            {
                v.push_back(input[i]);
            }
            return;
        }
        else if (it - n1 > k - 1)
        {
            myf(v, input, k, n1_n, it - n1);
        }
        else
        {
            for (int i = n1_n + 0; i <= n1_n + it - n1; ++i)
            {
                v.push_back(input[i]);
            }
            myf(v, input, k - (it - n1) - 1, n1_n + (it - n1) + 1, n2_n);
        }
    }

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        std::vector<int> v;

        if (input.empty())
            return v;

        if (k > input.size())
            return v;

        v.resize(k);
        myf(v, input, k, 0, input.size());
        return v;
    }
};

// using heap

class Solution
{
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        std::vector<int> v;

        if (input.empty())
            return v;

        if (k > input.size())
            return v;

        multiset<int, greater<int> > s;
        std::vector<int>::iterator it = input.begin();
        while (it != input.end())
        {
            if (s.size() < k)
            {
                s.insert(*it);
            }
            else
            {
                if (*(s.begin()) > *it)
                {
                    s.erase(s.begin());
                    s.insert(*it);
                }
            }
            it++;
        }

        v.resize(k);
        copy(s.begin(), s.end(), v.begin());

        return v;
    }
};