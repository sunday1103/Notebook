#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    char ch;
    while (getline(cin, str))
    {
        cin >> ch;
        cin.get();
        cout << str << endl;
        cout << ch << endl;
    }
    return 0;
}
