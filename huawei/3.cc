
#include <iostream>
#include <set>

using namespace std;

void myf(int N)
{
    set<int> s;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }

    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }
}

int main()
{
    int N;
    while (cin >> N)
        myf(N);
    return 0;
}
