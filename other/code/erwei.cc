#include <iostream>
#include <vector>
using namespace std;

vector<int> flag;

bool myf(int **grid, int m, int n, int i, int j)
{
    cout << (long)*(grid + i * m + j) << " - " << endl;
    if ((long)*(grid + i * m + j) == 9)
    {
        return 1;
    }

    bool l = 0;
    bool r = 0;
    bool u = 0;
    bool b = 0;

    if (j + 1 < n && (long)*(grid + i * m + j + 1) == 1 && flag[i * m + j + 1] == 0) //r
    {
        r = myf(grid, m, n, i, j + 1);
    }
    if (i + 1 < m && (long)*(grid + (i + 1) * m + j) == 1 && flag[(i + 1) * m + j] == 0) //b
    {
        b = myf(grid, m, n, i + 1, j);
    }
    if (j - 1 >= 0 && (long)*(grid + i * m + j - 1) == 1 && flag[i * m + j - 1] == 0) // l
    {
        r = myf(grid, m, n, i, j - 1);
    }
    if (i - 1 >= 0 && (long)*(grid + (i - 1) * m + j) == 1 && flag[(i - 1) * m + j] == 0)
    {
        r = myf(grid, m, n, i - 1, j);
    }

    return l & r & u & b;
}

int isPath(int **grid, int m, int n)
{
    flag.resize(m * n, 0);
    return myf(grid, m, n, 0, 0) ? 1 : 0;
}

int main()
{
    int grid[3][3] =
        {
            {1, 1, 1},
            {9, 1, 1},
            {0, 1, 0}};

    int **p = (int **)grid;

    cout << isPath(p, 3, 3) << endl;
    return 0;
}
