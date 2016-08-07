/*
class Solution {
 public:
  int Fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return Fibonacci(n - 1) + Fibonacci(n - 2);
  }
};
*/

class Solution {
 public:
  int Fibonacci(int n) {
    std::vector<int> v;
    v.resize(n + 1);
    if (n == 0) return 0;
    if (n == 1) return 1;
    v[0] = 0;
    v[1] = 1;
    for (int i = 2; i < n + 1; i++) {
      v[i] = v[i - 1] + v[i - 2];
    }
    return v[n];
  }
};