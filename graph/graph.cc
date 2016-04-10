#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  string ss;
  if (argc == 1) {
    cout << "Input expression: \n";
    getline(cin, ss);
  } else {
    ss = argv[1];
  }
  cout << "The expression is : " << ss << endl;
  ;
}
