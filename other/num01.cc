#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int digit(int n)
{
    int i = 0;
    while (n != 0)
    {
        i++;
        n = n / 10;
    }
    return i;
}

bool is_greater(int n)
{
    int d = digit(n);
    while (d > 0)
    {
        int a = n / pow(10, d - 1);
        if (a > 1)
        {
            return 1;
        }

        if (a == 0)
        {
            return 0;
        }

        n = n - a * pow(10, d - 1);
        d--;
    }
    return 1;
}

int count = 0;

void myf(int n)
{
    int d = digit(n);
    if (is_greater(n))
    {
        cout << count + pow(2, d) - 1 << endl;
        return;
    }

    count += pow(2, d - 1);
    int m = n % (int)pow(10, d - 1);
    myf(m);
}

int main()
{
    int n;
    cin >> n;
    myf(n);
}