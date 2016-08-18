#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool iszero(doubel a)
{
    if (a < 1e-10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

class data
{
  public:
    std::vector<double> v;
    double changdu;
    data(std::vector<double> v1) : v(v1)
    {
        double a = v[2] - v[0];
        double b = v[3] - v[1];
        changdu = a > b ? a : b;
    }
};

bool f1(data a, data b)
{
    if (a.changdu < b.changdu)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void myf()
{
    int n;
    cin >> n;

    vector<data> v;
    vector<data> v1;
    vector<data> v2;
    for (int i = 0; i < n; ++i)
    {
        std::vector<int> vv;
        vv.resize(4);
        for (int j = 0; j < 4; ++j)
        {
            cin >> vv[j];
        }

        double a = vv[2] - vv[0];
        double b = vv[3] - vv[1];
        if (a > 0)
        {
            v1.push_back(data(vv));
        }
        else
        {
            v2.push_back(data(vv));
        }
    }

    sort(v1.begin(), v1.end(), f1);
    sort(v2.begin(), v2.end(), f1);

    std::vector<int>::iterator it = v1.begin();
    for (; i != v1.end();)
    {
        std::vector<int>::iterator it1 = lower_bound(v1.begin(), v1.end(), *it, myf);
        std::vector<int>::iterator it2 = upper_bound(v1.begin(), v1.end(), *it, myf);
        i = it2 + 1;

        if (it1 != it2)
        {
            std::vector<data> vin(it1, it2);
            for (int k = 0; k < vin.size(); ++k)
            {
                for (int kk = k + 1; kk < vin.size(); ++kk)
                {
                    double ll = vin[kk].changdu - vin[k].changdu;
                    if (count(v2.begin(), v2.end(), ll) >= 2)
                    {
                        std::vector<int>::iterator it3 = lower_bound(v2.begin(), v2.end(), ll, myf);
                        std::vector<int>::iterator it4 = upper_bound(v2.begin(), v2.end(), ll, myf);
                        std::vector<data> vin2(it1, it2);
                    }
                }
            }
        }
    }
}

int main()
{
    int T;
    T = 1;
    for (int i = 0; i < T; ++i)
    {
        myf();
    }
    return 1;
}
