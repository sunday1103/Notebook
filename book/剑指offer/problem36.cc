#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution1
{
  public:
    int InversePairs(vector<int> data)
    {
        int count = 0;
        for (int i = 0; i < data.size(); ++i)
        {
            int a = data[i];
            for (int j = i + 1; j < data.size(); ++j)
            {
                if (a > data[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};

class Solution
{
  public:
    //merge
    int count;

    void merge(vector<int> &aux, std::vector<int> &a, int lo, int mid, int hi)
    {
        int i = lo;
        int j = mid + 1;
        // std::vector<int> aux;
        // aux.resize(a.size());
        for (size_t k = lo; k <= hi; k++)
        {
            aux[k] = a[k];
        }
        //cout << aux << endl;
        for (size_t k = lo; k <= hi; k++)
        {
            if (i > mid)
                a[k] = aux[j++];
            else if (j > hi)
                a[k] = aux[i++];
            else if (aux[i] <= aux[j])
                a[k] = aux[i++];
            else
            {
                a[k] = aux[j++];
                count += (mid - i + 1);
                count = count % 1000000007;
            }
        }
    }

    void merge_sort(vector<int> &aux, std::vector<int> &a, int lo, int hi)
    {
        if (hi <= lo)
        {
            return;
        }
        int mid = (lo + hi) / 2;
        merge_sort(aux, a, lo, mid);
        merge_sort(aux, a, mid + 1, hi);
        merge(aux, a, lo, mid, hi);
    }

    int InversePairs(vector<int> data)
    {
        if (data.size() == 0)
        {
            return 0;
        }

        count = 0;
        std::vector<int> aux;
        aux.resize(data.size());

        merge_sort(aux, data, 0, data.size() - 1);
        return count % 1000000007;
    }
};

int main()
{
    std::vector<int> v;
    int N;
    cin >> N;
    v.resize(N, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    Solution1 S1;
    cout << S1.InversePairs(v) << endl;

    Solution S;
    cout << S.InversePairs(v) << endl;
}