#include<iostream>
#include <string>

using namespace std;
class A
{
public:
	A(){a = 1;b=2;}
	int a;
	int & get_b(){return b;}
	void print_b(){cout<<b<<endl;}
private:
	int b;
};

int main()
{
	string a("1sdjsj");
	cout<<a<<endl;
	string b("");
	cout<<b<<endl;
	//string c(NULL);
	//cout<<c<<endl;
	return 0;
}