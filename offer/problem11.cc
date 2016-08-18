class Solution
{
  public:
    double Power(double base, int exponent)
    {
        int flag = 1;
        if (exponent == 0)
        {
            return 1;
        }
        else if (exponent > 0)
        {
        }
        else
        {
            flag = 0;
            exponent = 0 - exponent;
        }
        double p = 1;
        while (exponent)
        {
            p = p * base;
            exponent--;
        }

        return flag ? p : 1 / p;
    }
};