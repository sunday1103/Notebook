#include <iostream>
#include <algorithm>
#include <pthread.h>
using namespace std;

class my_heap
{
private:
    vector<int> &v;
    int size;
    pthread_mutex_t mutex;
public:
    my_heap();
    void swim(int k);
    void sink(int k);
    void insert(int v);
    int delMax();
    int delKey(int key);
    int delKey(int i, int key);
};

my_heap::my_heap()
{
    size = 1;
    pthread_mutex_init (&mutex, NULL);
}

int my_heap::delKey(int i, int k)
{
    if (key > v[i])
    {
        return 0;
    }

    if(key == v[i])
    {
        swap(v[i],v[size]);
        size--;
        sink(i);
        return 1;
    }

    if (i == size)
    {
        return 0;
    }

    return delKey(2*i,key) || delKey(2*i + 1,key);
}

int my_heap::delKey(int key)
{
    pthread_mutex_lock(&mutex);
    int flag = delKey(1,key);
    pthread_mutex_unlock(&mutex); 
    return flag;
}

int my_heap::delMax()
{
    int max = v[1];
    swap(v[1],v[size]);
    size--;
    sink(1);
    return max;
}

void my_heap::insert(int v)
{
    pthread_mutex_lock(&mutex);
    v.push_back(v);
    size++;
    swim(size - 1);
    pthread_mutex_unlock(&mutex); 
}


void my_heap::swim(int k)
{
    while (v[k] > v[k / 2] && k > 1)
    {
        swap(v[k], v[k / 2]);
        k = k / 2;
    }
}

void my_heap::sink(int k)
{
    while (2 * k < size)
    {
        int j = 2 * k;
        if (j + 1 < size && v[j] < v[j + 1])
        {
            j++;
        }

        if (v[k] >= v[j])
            break;

        swap(v[k], v[j]);

        k = j;
    }
}

