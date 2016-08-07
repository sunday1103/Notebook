#include <iostream>

using namespace std;

int main() {
  int a = 1;
  for (int i = 0; i <= 32; ++i) {
    cout << dec << i << " - " << (a << i) << " ---- "
         << "   " << hex << (a << i) << endl;
  }

  cout << (a << 32) << endl;
  cout << (a << 33) << endl;
  cout << (a << 34) << endl;

  cout << "------------------" << endl;
  cout << dec;
  int i = 1;
  int n = 10;
  int num = 0;
  while (i) {
    if (n & i) num++;  //= n & i;
    i = i << 1;
    cout << "i " << dec << i << "   " << hex << (a << i) << endl;
  }
  cout << num << endl;
  cout << dec;

  cout << "============" << endl << endl;
  int b = 1;
  cout << (b << 32) << endl;
  int c = b << 32;
  cout << c << endl;

  b = b << 31;
  b = b << 1;
  cout << b << endl;

  b = 1;
  int f = b << -1;
  cout << f << endl;
}