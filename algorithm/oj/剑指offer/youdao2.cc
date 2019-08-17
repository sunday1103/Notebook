#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void myf()
{
    int n;
    cin >> n;

    std::vector<int> v;
    for (int i = n; i > 0; i--)
    {
        v.push_back(i);
    }

    std::vector<int> q;
    for (int i = 0; i < n; ++i)
    {
        int a = v[i];
        q.push_back(a);
        q.push_back(q[0]);
        q.erase(q.begin());
    }

    reverse(q.begin(), q.end());

    for (int i = 0; i < q.size() - 1; ++i)
    {
        cout << q[i] << " ";
    }
    cout << q[q.size() - 1];
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        myf();
    }
    return 0;
}
