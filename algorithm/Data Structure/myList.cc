#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

#define N 10

class List
{
  private:
    int *arr;
    int head, tail;
    int size;

  public:
    List();
    List(int n);
    ~List();
    void push_back(int n);
    int front();
    void pop_front();
};

List::List()
{
    arr = new int[N + 1];
    head = 0;
    tail = 0;
    size = N;
}

List::List(int n)
{
    arr = new int[n + 1];
    head = 0;
    tail = 0;
    size = n;
}

void List::push_back(int n)
{
    if ((tail + 1) % (size + 1) == head)
    {
        cout << " fail: full!" << endl;
        return;
    }
    arr[tail] = n;
    tail = (tail + 1) % (size + 1);
    cout << "push_back a " << n << ", " << tail << " " << head << endl;
}

int List::front()
{
    return arr[head];
}

void List::pop_front()
{
    if (tail == head)
    {
        cout << " fail: empty!" << endl;
        return;
    }

    head = (head + 1) % (size + 1);
}

List::~List()
{
    delete[] arr;
}

int main()
{
    List L(5);
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    L.push_back(6);

    cout << L.front() << endl;
    cout << L.front() << endl;

    L.pop_front();
    cout << L.front() << endl;

    L.pop_front();
    L.pop_front();
    L.pop_front();
    L.pop_front();
    L.pop_front();
    L.pop_front();
}