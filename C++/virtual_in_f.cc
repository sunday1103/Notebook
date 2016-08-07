#include <iostream>

using namespace std;
class Base
{
  public:
    virtual void f1();
	void f2();
};

void Base::f1()
{
    cout << "base f1" << endl;
}

void Base::f2()
{
	cout << "base f2" << endl;
	f1();
}

class Derived : public Base
{
  public:
    virtual void f1();
	void f2();
	void f3();
};

void Derived::f1()
{
	cout << "Derived f1" << endl;
}

void Derived::f2()
{
	cout << "Derived f2" << endl;
	f1();
}

void Derived::f3()
{
	cout << "Derived f3" << endl;
}

int main()
{
    Base A;
	Derived B;
    Base *pA = &B;
	Derived *pB = &B;
	pA->f1();
	cout<<endl;
	pA->f2();
	cout<<endl;
	pB->f2();
	cout<<endl;
	A.f1();
	A.f2();
	cout<<"-------"<<endl;
	(*pA).f1();
	
}