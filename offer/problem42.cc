#include "my_include.h"

class Solution
{
  public:
    string ReverseSentence(string str)
    {
        string sb;
        if (str.length() == 0)
        {
            return sb;
        }

        std::vector<string> v;
        string s;
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] != ' ')
            {
                s += str[i];
            }
            else
            {
                v.push_back(s);
                s = "";
            }
        }
        v.push_back(s);

        reverse(v.begin(), v.end());

        sb += v[0];
        for (int i = 1; i < v.size(); ++i)
        {
            sb += " " + v[i];
        }
        return sb;
    }
};

int main()
{
    Solution S;
    string s("student. a am I");
    cout << s << endl;
    cout << S.ReverseSentence(s) << endl;
}