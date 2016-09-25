#include <iostream>

using namespace std;

class base
{
  public:
    int a;

  protected:
    int b;

  private:
    int c;
};

class foo
{
    int a;

  public:
    int foobar(foo *f)
    {
        return this->a + f->a;
    }
    foo(int b) : a(b) {}
};

// 友元
class A
{
    friend void myf(A *pa);
    int a;
};

void myf(A *pa)
{
    cout << pa->a << endl;
}

//常规继承

class A1
{
  protected:
    int a;

  private:
    int b;

  public:
    int c;
};

class A2 : public A1
{
    int b;
    void f1()
    {
        a;
        b;
        c;
    }
};

//多重继承
class B1
{
  public:
    int a;
};

class B2 : private B1
{
  public:
    int b;
    void f1()
    {
        a;
    }
    using B1::a;
};

class B3 : private B2
{
    int c;
    void f1()
    {
        a;
        b;
        c;
    }
};

int main(int argc, char const *argv[])
{
    // ----------class-based control
    foo f1(1);
    foo f2(2);
    cout << f1.foobar(&f2) << endl;
    // -------------

    A A1;
    myf(&A1);

    return 0;
}