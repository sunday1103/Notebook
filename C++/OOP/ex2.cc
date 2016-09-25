#include <iostream>
using namespace std;

class A
{
  public:
    void virtual f()
    {
        cout << "A" << endl;
    }
};

class B : public A
{
  public:
    void virtual f()
    {
        cout << "B" << endl;
    }
};

int main()
{
    A *pa = new A();
    pa->f();
    B *pb = (B *)pa;
    pb->f();

    delete pa, pb;
    pa = new B();
    pa->f();
    pb = (B *)pa;
    pb->f();

    return 0;
}