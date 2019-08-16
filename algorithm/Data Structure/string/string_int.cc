/*
C++11 : g++ -std=c++11 11.cc
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    // C++11 method
   //  cout << "98:------------" << endl;
   //  int a = 10;
   //  cout << a << endl;
   //  string s = to_string(a);
   //  cout << s << endl;
   //  string s1("12.021");
   //  double a1 = stod(s1);
   //  int a2 = stoi(s1);
   //  cout << a1 << endl;
   //  cout << a1 << endl;
   //  // C++ 98 method
    cout << "98:------------" << endl;
    int a3 = 10;
    ostringstream ss;
    ss << a3;
    string s11 = ss.str();
    cout << s11 << endl;
    string s2("12.021 19");
    istringstream iss(s2);
    double a4;
    int a5;
    iss >> a4;
    iss >> a5;
    cout << a4 << endl;
    cout << a5 << endl;
    // getline ---------------
    cout << "getline ---------------" << endl;
    istringstream iss1("ssjdsjdjsjdsj \n =djsjdsjksdsdkskdsks");
    string st1;
    getline(iss1, st1);
    istringstream iss2(st1);
    char c1;
    iss2 >> c1;
    cout << c1 << endl;
    getline(iss1, st1);
    istringstream iss3(st1);
    iss3 >> c1;
    cout << c1 << endl;
	// char...................
	char c = '9';
	int cccint = a;
	int cccint1 = a - '0';
	cout<<c<<endl;
	cout<<cccint<<endl;
	cout<<cccint1<<endl;
}
