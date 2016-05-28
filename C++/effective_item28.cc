#include<iostream>

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
	A A1;
	A1.print_b();
	A1.get_b() = 3;
	A1.print_b();
	//cout<<A1.b;
	return 0;
}