#include <iostream>
#include <string>

using namespace std;

void myf(string &s)
{
    int n = s.length();
    n--;
    char c = s[n];
    int l = 0;
    while (c != ' ' && n >= 0)
    {
        l++;
        n--;
        c = s[n];
    }
    cout << l << endl;
}

int main()
{
    string s;

    while (getline(cin, s))
    {
        myf(s);
    }
}