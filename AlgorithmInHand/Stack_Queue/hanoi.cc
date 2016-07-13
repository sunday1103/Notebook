#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void hanoi(int n, char x, char y, char z)
{
    if (n == 1)
    {
        cout << n << " from " << x << " to " << z << endl;
    }
    else
    {
        hanoi(n - 1, x, z, y);
        cout << n << " from " << x << " to " << z << endl;
        hanoi(n - 1, y, x, z);
    }
}

int main()
{
    int n;
    cout << "Input the number:\n";
    cin >> n;
    cout << (1 << n) - 1 << " :" << endl;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
