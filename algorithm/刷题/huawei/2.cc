#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int myf(string &s, char c)
{
    if (
        !(
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z')))
    {
        return count(s.begin(), s.end(), c);
    }

    char c1;
    if (c < 'A')
    {
        c1 = c + 'A' - 'a';
    }
    else
    {
        c1 = c - ('A' - 'a');
    }
    return count(s.begin(), s.end(), c) +
           count(s.begin(), s.end(), c1);
}

int main()
{
    string s;
    char c;
    while (getline(cin, s))
    {
        cin >> c;
        getchar();
        cout << myf(s, c) << endl;
    }
}