#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int a = 0;
    int a1 = 0;
    int b = a++;
    int c = ++a1;
    cout << "b " << b << "a " << a << endl;
    cout << "c " << c << "a1 " << a1 << endl;
}
