class Solution
{
  public:
    int countDigitOne(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        if (n < 10)
        {
            return 1;
        }

        long long num = 0;

        int base = 10;
        int d = 1;
        while (n / base)
        {
            base *= 10;
            d += 1;
        }

        long long num1 = pow(10, d - 2) * (d - 1);
        int mm = n / (base / 10);
        num = num1 * mm;

        if (mm > 1)
        {
            num = num + pow(10, d - 1);
        }

        if (mm == 1)
        {
            num += n % (base / 10) + 1;
            return num;
        }

        num = num + countDigitOne(n % (base / 10));

        return num;
    }
};