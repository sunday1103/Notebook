#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define MAX 10000

int output(int a[], int b[], int N)
{
    sort(a, a + N);
    sort(b, b + N);
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < N; i++)
    {
        pq.push(a[i] + b[0]);
    }
    for (int i = 0; i < N - 1; i++)
    {
        int m = pq.top();
        pq.pop();
        cout << m << " ";
        pq.push(b[i + 1] + a[0]);
    }
    cout << pq.top();
}

int main()
{
    int a[MAX], b[MAX];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
        cin >> b[i];
    output(a, b, N);
    return 0;
}
