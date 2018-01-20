#include <iostream>

using namespace std;

int &f1(int a)
{
    int &b = a;
    return b;
}

int main()
{
    int a = 0;
    int b = 0;
    int c = 1;
    //a *b = c; // error expression
    cout << f1(c) << endl;
    f1(b) = 2;
    cout << f1(b) << endl;
}

class TextBlock
{
};
