#include <iostream>
#include <vector>
#include <string>
#include <time.h> //used to call time
#include <cstdlib>

using namespace std;

void print(const std::vector<int> &v, string s)
{
    cout<<s<<endl;
    for (int i = 0; i < v.size()-1; i++)
    {
        cout<<v[i]<<" , ";
    }
    cout<<v[v.size()-1];
    cout<<endl;
}


int binary_search(std::vector<int> &data, const int target)
{
    int left = 0;
    int right = data.size()-1;
    int mid = right;
    while(left < right)
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
}

void select_sort(std::vector<int> &data, const int start, const int end)
{

}

int main()
{
    std::vector<int> data;
    cout << "input vector ended with a non-number:\n";
    int a;
    while(cin >>  a)
        data.push_back(a);
    string s("input data is: ");
    //print(data,s);

    clock_t start_time = clock();
    cout<<"start_time is "<<start_time<<endl;
    binary_insert_sort(data,0,data.size());
    clock_t end_time = clock();
    if (!verify(data))
    {
        abort();
    }
    cout<<"end_time is "<<end_time<<endl;
    cout<<"total "<<end_time - start_time<<endl;
    s = "sorted data is: ";
    //print(data,s);
    cout<<"total "<<end_time - start_time<< "  clock "<<endl;
    cout<<"total time "<<((float)(end_time - start_time))/CLOCKS_PER_SEC<< "  sec "<<endl;
}
