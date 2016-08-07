#include <iostream>
#include <vector>

using namespace std;

/*
class BinarySearch
{
  public:
    int getPos(vector<int> A, int n, int val)
    {
        if (n == 0)
            return -1;
        if (n == 1)
            return A[0] == val ? 0 : -1;
        int i = 0;
        int j = n - 1;
        int mid = (i + j) / 2;
        while (i != mid)
        {
            if (A[mid] < val)
            {
                i = mid;
            }
            else if (A[mid] >= val)
            {
                j = mid;
            }
            mid = (i + j) / 2;
        }
        if (A[i] == val)
            return i;
        if (A[j] == val)
            return j;
        else
            return -1;
    }
};
*/

//如果找到，如果重复，则返回最小序号
class BinarySearch {
 public:
  int getPos(vector<int> A, int n, int val) {
    if (n == 0) return -1;
    if (n == 1) return A[0] == val ? 0 : -1;
    int i = 0;
    int j = n - 1;
    int mid;
    while (i <= j) {
      mid = (i + j) / 2;
      if (A[mid] < val) {
        i = mid + 1;
      } else if (A[mid] >= val) {
        j = mid - 1;
      }
    }
    cout << "in getpos i = " << i << endl;
    if (A[i] == val)
      return i;
    else
      return -1;
  }
};

// 返回最大序号
class BinarySearch1 {
 public:
  int getPos(vector<int> A, int n, int val) {
    if (n == 0) return -1;
    if (n == 1) return A[0] == val ? 0 : -1;
    int i = 0;
    int j = n - 1;
    int mid;
    while (i <= j) {
      mid = (i + j) / 2;
      if (A[mid] <= val) {
        i = mid + 1;
      } else if (A[mid] > val) {
        j = mid - 1;
      }
    }
    cout << "in getpos i = " << i << endl;
    if (A[j] == val)
      return j;
    else
      return -1;
  }
};

int main() {
  int N;
  cin >> N;
  std::vector<int> v;
  v.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  BinarySearch B;
  int val;
  cin >> val;
  int pos = B.getPos(v, N, val);
  cout << "pos " << pos << endl;

  BinarySearch1 B1;
  cout << "pos1 " << B1.getPos(v, N, val) << endl;
}