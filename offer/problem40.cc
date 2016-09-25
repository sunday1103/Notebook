class Solution
{
  public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        int a = 0;
        for (int i = 0; i < data.size(); ++i)
        {
            a ^= data[i];
        }

        int n = 0;
        while (!(a >> n & 1))
            n++;

        int r1 = 0;
        int r2 = 0;
        for (int i = 0; i < data.size(); ++i)
        {
            if (data[i] >> n & 1)
                r1 ^= data[i];
            else
                r2 ^= data[i];
        }

        *num1 = r1;
        *num2 = r2;
    }
};