#include <algorithm>

class Solution
{
  public:
    vector<string> Permutation(string str)
    {
        vector<string> s;

        if (str.length() == 0)
        {
            return s;
        }

        sort(str.begin(), str.end());
        do
        {
            s.push_back(str);
        } while (next_permutation(str.begin(), str.end()));
        return s;
    }
};