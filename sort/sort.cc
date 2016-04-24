#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h> //used to cal time
#include <vector>

using namespace std;

void print(const std::vector<int> &v, string s)
{
    cout << s << endl;
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << " , ";
    }
    cout << v[v.size() - 1];
    cout << endl;
}

void insert_sort(std::vector<int> &data, const int start, const int end)
{
    //int n = data.size();
    int j;
    for (int i = start + 1; i < end; i++)
    {
        int temp = data[i];
        for (j = i; j > start && temp < data[j - 1]; j--)
        {
            data[j] = data[j - 1];
        }
        data[j] = temp;
    }
}

void binary_insert_sort(std::vector<int> &data, const int start, const int end)
{
    for (int i = start + 1; i < end; i++)
    {
        int temp = data[i];

        //find the position from [start,i-1] subject to data[pos] <= temp <= data[pos+1]
        int left = start;
        int right = i - 1;
        int mid = right;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (temp < data[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        for (int m = i; m > left; m--)
        {
            data[m] = data[m - 1];
        }

        data[left] = temp;
    }
}

void select_sort(std::vector<int> &data, const int start, const int end)
{
    int index = 0;
    int value = 0;
    for (int i = 0; i < data.size(); i++)
    {
        index = i;
        value = data[index];
        for (int j = i + 1; j < data.size(); j++)
        {
            if (data[j] < value)
            {
                value = data[j];
                index = j;
            }
        }
        int temp = data[i];
        data[i] = data[index];
        data[index] = temp;
    }
}

bool verify(std::vector<int> &data)
{
    for (int i = 1; i < data.size(); ++i)
    {
        if (data[i] < data[i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    std::vector<int> data;
    cout << "input vector ended with a non-number:\n";
    int a;
    while (cin >> a)
        data.push_back(a);
    string s("input data is: ");
    //print(data,s);

    //1. insert_sort
    std::vector<int> data1;
    data1 = data;
    clock_t start_time = clock();
    //cout << "start_time is " << start_time << endl;
    insert_sort(data1, 0, data1.size());
    clock_t end_time = clock();
    if (!verify(data1))
    {
        cout << "wrong sort\n";
        abort();
    }
    //cout << "end_time is " << end_time << endl;
    //cout << "total " << end_time - start_time << endl;
    s = "sorted data is: ";
    //print(data,s);
    //cout << "total " << end_time - start_time << "  clock " << endl;
    cout << "insert_sort: " << endl;
    cout << "total time " << ((float)(end_time - start_time)) / CLOCKS_PER_SEC << "  sec " << endl;
    cout << "--------" << endl;

    //2. binary_insert_sort
    std::vector<int> data2;
    data2 = data;
    start_time = clock();
    binary_insert_sort(data2, 0, data2.size());
    end_time = clock();
    if (!verify(data2))
    {
        cout << "wrong sort\n";
        abort();
    }
    cout << "binary_insert_sort: " << endl;
    cout << "total time " << ((float)(end_time - start_time)) / CLOCKS_PER_SEC << "  sec " << endl;
    cout << "--------" << endl;

    //2. select_sort
    std::vector<int> data3;
    data3 = data;
    start_time = clock();
    select_sort(data3, 0, data3.size());
    end_time = clock();
    if (!verify(data2))
    {
        cout << "wrong sort\n";
        abort();
    }
    cout << "select_sort: " << endl;
    cout << "total time " << ((float)(end_time - start_time)) / CLOCKS_PER_SEC << "  sec " << endl;
    cout << "--------" << endl;
}
