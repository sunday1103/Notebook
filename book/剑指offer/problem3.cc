class Solution
{
  public:
    bool Find(vector<vector<int> > array, int target)
    {
        int m = array.size();
        if (m == 0)
            return false;
        int n = array[0].size();
        if (n == 0)
            return false;
        int i = 0;
        int j = n - 1;
        while (i != m && j != -1)
        {
            if (array[i][j] == target)
                return true;
            else if (array[i][j] < target)
            {
                i = i + 1;
            }
            else
            {
                j = j - 1;
            }
        }
        return false;
    }
};