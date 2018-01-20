#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

// int main()
// {
//     int N;
//     cin >> N;
//     for (unsigned int i = 1; i < pow(10, N); ++i)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
// }

void print_s(char *s)
{
    cout << s << " ";
}

void myf(char *s, int length, int index)
{
    if (index == length - 1)
    {
        print_s(s);
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        s[index + 1] = i + '0';
        myf(s, length, index + 1);
    }
}

int main()
{
    int N;
    cin >> N;
    char *s = new char[N + 1];
    s[N] = '\0';
    for (int i = 0; i < 10; ++i)
    {
        s[0] = i + '0';
        myf(s, N, 0);
    }
    cout << endl;
}
