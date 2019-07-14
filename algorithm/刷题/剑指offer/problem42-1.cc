class Solution
{
  public:
    string LeftRotateString(string str, int n)
    {
        if (str.length() == 0)
        {
            return str;
        }

        int m = n % str.length();
        string sb;
        for (int i = m; i < str.length(); ++i)
        {
            sb += str[i];
        }
        for (int i = 0; i < m; ++i)
        {
            sb += str[i];
        }
        return sb;
    }
};