#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void myf()
{
    int n, k;
    cin >> n >> k;
    std::vector<int> v;
    v.resize(2 * n);

    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> v[i];
    }

    for (int i = 0; i < k; ++i)
    {
        std::vector<int> v1(v.begin(), v.begin() + n);
        std::vector<int> v2(v.begin() + n, v.end());

        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());

        v.clear();
        for (int j = 0; j < n; ++j)
        {
            v.push_back(v2[j]);
            v.push_back(v1[j]);
        }
        reverse(v.begin(), v.end());
    }

    for (int i = 0; i < 2 * n - 1; ++i)
    {
        cout << v[i] << " ";
    }
    cout << v[2 * n - 1];
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
}
