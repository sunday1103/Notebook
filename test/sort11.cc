// sort algorithm example
#include <algorithm> // std::sort
#include <iostream>  // std::cout
#include <vector>    // std::vector

using namespace std;

bool myfunction(vector<int> i, vector<int> j)
{
    if (i[1] > j[1])
        return true;
}

int main()
{
    vector<vector<int> > v;
    std::vector<int> v1;
    v1.resize(2);

    v1[0] = 0;
    v1[1] = 5;

    v.push_back(v1);

    v1[0] = 1;
    v1[1] = 6;
    v.push_back(v1);

    v1[0] = 3;
    v1[1] = 2;
    v.push_back(v1);

    v1[0] = 2;
    v1[1] = 24;
    v.push_back(v1);

    //  v: (0, 5) (1, 6)

    std::sort(v.begin(), v.end(), myfunction); // 12 32 45 71(26 33 53 80)

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i][0] << " " << v[i][1] << endl;
    }

    return 0;
}