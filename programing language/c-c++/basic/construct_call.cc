#include <cstdlib>
#include <iostream>

using namespace std;

class A
{
  public:
    int a;
    int a1;
    A() : a(1) { cout << "called A()\n"; }
    ~A() { cout << "called ~A()" << endl; }
};

class B
{
  public:
    double b;
    B(int b1) : b(b1) { cout << "called B(int)\n"; }
    B() { B(2); }
    // B(double b2) : B(3) {}  //C++11 is ok
    ~B() { cout << "called ~B()" << endl; }
};

int main()
{
    // B B1(5);
    // cout << B1.b << endl;

    // B B2;
    // cout << B2.b << endl;

    // B B3(1.2);
    // cout << B3.b << endl;

    // cout << "----------\n";

    // A *pa = (A *)malloc(sizeof(A));
    // cout << pa->a << endl;
    // pa->~A();
    // cout << "----------\n";
    // pa = new (pa) A;
    // cout << pa->a << endl;
    // // pa->A::A();
    // cout << "----------\n";

    // cout << "----------\n";

    A *pa1 = new A;

    //  pa1->~A();
    //  delete pa1;

    B *pb1 = new (pa1) B(5);

    pb1->~B();
    ::operator delete(pb1);
    // delete pa1;

    return 0;
}