
#include <cmath>
#include <iostream>
#include <set>
#include <string>

using namespace std;

void myf(string s)
{
    int n = s.length();
    int num = 0;
    for (int i = 2; i < n; i++)
    {
        char c = s[i];
        int a;
        if (c >= '0' && c <= '9')
        {
            a = c - '0';
        }
        else
        {
            a = c - 'A' + 10;
        }

        num += a * pow(16, n - i - 1);
    }
    cout << num << endl;
}

int main()
{
    string s;
    while (cin >> s)
        myf(s);
    return 0;
}
