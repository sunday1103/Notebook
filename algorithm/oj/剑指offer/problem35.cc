#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

bool FindChar(char *pInputString, char *pChar)
{
    int len = strlen(pInputString);
    char *c = pInputString;
    while (*c != '\0')
    {
        if (count(pInputString, pInputString + len, *c) == 1)
        {
            *pChar = *c;
            return 1;
        }
        c++;
    }
    *pChar = '.';
    return 0;
}

int main()
{
    char s[1000];
    while (cin >> s)
    {
        char c;
        FindChar(s, &c);
        cout << c << endl;
    }
}