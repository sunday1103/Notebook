
#include <iostream>
#include <set>
#include <string>

using namespace std;

void myf(string s)
{
    for (int k = 0; k <= 1; k++)
    {
        if (k == 1)
        {
            cin >> s;
        }
        int i = 0;
        for (; i < s.length(); i++)
        {
            if (i % 8 == 0 && i != 0)
            {
                cout << endl;
                cout << s[i];
            }
            else
            {
                cout << s[i];
            }
        }

        while (i % 8 != 0)
        {
            cout << 0;
            i++;
        }

        cout << endl;
    }
}

int main()
{
    string s;
    while (cin >> s)
        myf(s);
    return 0;
}
