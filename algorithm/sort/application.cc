#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h> //used to cal time
#include <vector>

using namespace std;

ostream &operator<<(ostream &o, std::vector<int> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        o << v[i] << "\t";
    }
    return o;
}

std::vector<int> randomize(std::vector<int> a)
{
    srand(time(NULL));
    for (int i = 0; i < a.size() - 1; ++i)
    {
        // cout << rand() << endl;
        int m = (rand() % (a.size() - i - 1)) + 1;
        int temp = a[i];
        a[i] = a[i + m];
        a[i + m] = temp;
    }
    return a;
}

void find_repeat()
{
    std::vector<int> data;
    int a;
    while (cin >> a)
        data.push_back(a);
    sort(data.begin(), data.end());
    cout << data << endl;
    int count = 0;
    for (int i = 1; i < data.size(); ++i)
    {
        count++;
        if (data[i] != data[i - 1])
        {
            cout << count << "\t";
            count = 0;
        }
    }
}

int kendall_distance_1(const std::vector<int> &a, const std::vector<int> &b)
{
    std::vector<int> ainv;
    cout << a << endl;
    for (int i = 0; i < a.size(); ++i)
    {
        ainv[a[i]] = i;
    }

    std::vector<int> binv;
    for (int i = 0; i < b.size(); ++i)
    {
        binv[i] = ainv[b[i]];
    }

    // i < j, binv[i] > binv[j]
}

int kendall_distance_2(const std::vector<int> &a, const std::vector<int> &b)
{
}

void kendall_distance()
{
    std::vector<int> data;
    int a;
    while (cin >> a)
        data.push_back(a);
    if (data.size() == 0)
    {
        for (int i = 0; i < 1000; ++i)
        {
            data.push_back(i);
        }
    }
    std::vector<int> data1;
    data1 = randomize(data);
    cout << data << endl;
    cout << data1 << endl;
    clock_t start_time;
    clock_t end_time;
    start_time = clock();
    int r1 = kendall_distance_1(data, data1);
    end_time = clock();
    cout << "total time " << ((float)(end_time - start_time)) / CLOCKS_PER_SEC << "  sec " << endl;
    start_time = clock();
    int r2 = kendall_distance_2(data, data1);
    end_time = clock();
    cout << "total time " << ((float)(end_time - start_time)) / CLOCKS_PER_SEC << "  sec " << endl;
}

int main()
{
    //find_repeat();
    kendall_distance();
}