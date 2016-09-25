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

//---------------------merge------------------
std::vector<int> aux;
// merge
void merge(std::vector<int> &a, int lo, int mid, int hi)
{
    int i = lo;
    int j = mid + 1;

    for (int k = lo; k <= hi; k++)
    {
        aux[k] = a[k];
    }
    // cout << aux << endl;
    for (int k = lo; k <= hi; k++)
    {
        if (i > mid)
            a[k] = aux[j++];
        else if (j > hi)
            a[k] = aux[i++];
        else if (aux[i] < aux[j])
            a[k] = aux[i++];
        else
            a[k] = aux[j++];
    }
}

void merge_sort(std::vector<int> &a, int lo, int hi)
{
    if (hi <= lo)
    {
        return;
    }
    int mid = (lo + hi) / 2;
    merge_sort(a, lo, mid);
    merge_sort(a, mid + 1, hi);
    merge(a, lo, mid, hi);
    // cout << a << endl;
}

void use_merge_sort(std::vector<int> a)
{
    aux.resize(a.size());
    merge_sort(a, 0, a.size() - 1);
}

//---------------------merge end------------------

//---------------------quick------------------

int partition(vector<int> &a, int lo, int hi)
{
    int i = lo;
    int j = hi + 1;
    int p = a[i];
    while (1)
    {
        while (a[++i] < p && i < hi)
            ;
        while (a[--j] > p)
            ; // no need to judge j >= lo
        if (i >= j)
            break;
        swap(a[i], a[j]);
    }
    swap(a[lo], a[j]);
    return j;
}

void quick_sort(std::vector<int> &a, int lo, int hi)
{
    if (lo <= hi)
    {
        int j = partition(a, lo, hi);
        quick_sort(a, lo, j - 1);
        quick_sort(a, j + 1, hi);
    }
}

//---------------------quick end------------------

//---------------------heap------------------

void swim(vector<int> &v, int k, int N)
{
    while (v[k] > v[k / 2] && k > 1)
    {
        swap(v[k], v[k / 2]);
        k = k / 2;
    }
}

void sink(vector<int> &v, int k, int N)
{
    while (2 * k < N)
    {
        int j = 2 * k;
        if (j + 1 < N && v[j] < v[j + 1])
        {
            j++;
        }

        if (v[k] >= v[j])
            break;

        swap(v[k], v[j]);

        k = j;
    }
}

void heap_sort(vector<int> &v)
{
    int N = v.size();
    for (int i = N / 2; i >= 1; --i)
    {
        sink(v, i, N);
    }

    while (N > 1)
    {
        N--;
        swap(v[1], v[N]);
        sink(v, 1, N);
    }
}

//---------------------heap end------------------

int main()
{
    int aa[] = {6, 3, 4, 5, 8, 2, 5, 6, 10, 12};
    std::vector<int> data(aa, aa + sizeof(aa) / sizeof(int));

    quick_sort(data, 0, data.size() - 1);
    cout << data << endl;

    use_merge_sort(data);
    cout << data << endl;

    std::vector<int> v(data);
    v.insert(v.begin(), 0);
    heap_sort(v);
    cout << v << endl;
}

/*
Algorithm       Average     Best        Worst       extra space       stable
冒泡排序        O(N^2)      O(N)        O(N^2)      O(1)              稳定
直接插入排序    O(N^2)      O(N)        O(N^2)      O(1)              稳定
折半插入排序    O(NlogN)    O(NlogN)    O(N^2)      O(1)              稳定
简单选择排序    O(N^2)      O(N^2)      O(N^2)      O(1)              不稳定
快速排序        O(NlogN)    O(NlogN)    O(N^2)      O(logN)~O(N^2)    不稳定
归并排序        O(NlogN)    O(NlogN)    O(NlogN)    O(N)              稳定
堆排序          O(NlogN)    O(NlogN)    O(NlogN)    O(1)              不稳定
计数排序        O(d*(N+K))  O(d*(N+K))  O(d*(N+K))  O(N+K)            稳定
*/