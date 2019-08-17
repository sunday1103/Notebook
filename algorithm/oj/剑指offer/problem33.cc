#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

// 1-------------------------
class Solution
{
  public:
    string my_n_to_s(int num)
    {
        string s;
        ostringstream o;
        o << num;
        s = o.str();
        return s;
    }

    int my_s_to_n(string s)
    {
        int a;
        istringstream i(s);
        i >> a;
        return a;
    }

    bool f1(string a, string b)
    {
        int an = a.length();
        int bn = b.length();
        int x = my_s_to_n(a) + my_s_to_n(b) * pow(10, an);
        int y = my_s_to_n(b) + my_s_to_n(a) * pow(10, bn);

        if (x > y)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    string PrintMinNumber(vector<int> numbers)
    {
        string s;
        if (numbers.size() == 0)
        {
            return s;
        }

        vector<string> v;
        v.push_back(my_n_to_s(numbers[0]));
        for (int i = 1; i < numbers.size(); ++i)
        {
            string a = my_n_to_s(numbers[i]);
            int j = 0;
            for (; j < v.size(); ++j)
            {
                if (f1(a, v[j]))
                {
                    v.insert(v.begin() + j, a);
                    break;
                }
            }
            if (j == v.size())
            {
                v.push_back(a);
            }
        }

        for (int i = 0; i < v.size(); ++i)
        {
            s += v[i];
        }
        return s;
    }
};

//----------------------------------
string my_n_to_s(int num)
{
    string s;
    ostringstream o;
    o << num;
    s = o.str();
    return s;
}

int my_s_to_n(string s)
{
    int a;
    istringstream i(s);
    i >> a;
    return a;
}

bool f1(string a, string b)
{
    int an = a.length();
    int bn = b.length();
    int x = my_s_to_n(a) + my_s_to_n(b) * pow(10, an);
    int y = my_s_to_n(b) + my_s_to_n(a) * pow(10, bn);

    if (x > y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

class Solution1
{
  public:
    string PrintMinNumber(vector<int> numbers)
    {
        string s;
        if (numbers.size() == 0)
        {
            return s;
        }

        vector<string> v;
        for (int i = 0; i < numbers.size(); ++i)
        {
            v.push_back(my_n_to_s(numbers[i]));
        }

        sort(v.begin(), v.end(), f1);

        for (int i = 0; i < v.size(); ++i)
        {
            s += v[i];
        }
        return s;
    }
};

int main()
{
    int a[5] = {3, 5, 1, 4, 2};
    std::vector<int> v(a, a + 5);

    Solution S;
    cout << S.PrintMinNumber(v) << endl;
}