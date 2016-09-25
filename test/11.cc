#include <cmath>
#include <iostream>

using namespace std;

void foo(int n, int m, std::vector<int> A, std::vector<int> M1, std::vector<int> M2)
{
    if (m)
    {
        /* code */
    }
}

int main()
{
    int n, m;

    while (cin >> n >> m)
    {
        std::vector<int> A;
        A.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }

        std::vector<int> M1;
        std::vector<int> M2;
        M1.resize(m);
        M2.resize(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> M1[i] >> M2[i];
        }
    }
}