#include <iostream>

using namespace std;

class A
{
public:
	int a;
	void f1(A *pa){a = 1; this = pa;}
	void f2() const {a = 1; b =2;}
	static int b;
};

int A::b = 1;

int main()
{
	A A1,A2;
	A1.f1(&A2);
	A1.f2();
}
