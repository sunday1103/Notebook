class Solution
{
  public:
    bool myf(std::vector<int> v, int m, int n)
    {
        if (m >= n)
        {
            return 1;
        }
        int i = m;
        while (v[i] < v[n])
        {
            i++;
        }

        int j = n - 1;
        while (v[j] > v[n])
        {
            j--;
        }

        if (j + 1 == i)
        {
            return myf(v, m, j) && myf(v, i, n - 1);
        }
        else
        {
            return 0;
        }
    }
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.empty())
        {
            return 0;
        }
        else
        {
            return myf(sequence, 0, sequence.size() - 1);
        }
    }
};