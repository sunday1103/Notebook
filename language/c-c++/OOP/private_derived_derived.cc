#include <iostream>

using namespace std;

class B1
{
  public:
    int a;
    virtual void f2() { cout << "in B1 " << endl; }
};

class B2 : private B1
{
  public:
    int b;
    void f1()
    {
        a;
    }
    virtual void f2() { cout << "in B2 " << endl; }
    void f3()
    {
        B1 *p1 = new B2;
    }
};

class B3 : private B2
{
  public:
    int c;
    void f1()
    {
        // a;
        b;
        c;
    }
    virtual void f2() { cout << "in B3 " << endl; }
};

class Wilma
{
  protected:
    void fredCallsWilma()
    {
        std::cout << "Wilma::fredCallsWilma()\n";
        wilmaCallsFred();
    }
    virtual void wilmaCallsFred() = 0; // A pure virtual function
};

class Fred : private Wilma
{
  public:
    void barney()
    {
        std::cout << "Fred::barney()\n";
        Wilma::fredCallsWilma();
    }

  protected:
    virtual void wilmaCallsFred()
    {
        std::cout << "Fred::wilmaCallsFred()\n";
    }
};

int main(int argc, char const *argv[])
{
    B1 *p1 = new B1;
    B2 *p2 = new B2;
    B3 *p3 = new B3;

    p1->f2();
    p2->f2();
    p3->f2();

    cout << "--------" << endl;
    // p1 = (B1 *)p2;
    p1 = reinterpret_cast<B1 *>(p2);
    p1->f2();

    // p1 = p3;
    p1 = (B1 *)p3;
    p1->f2();

    cout << "--------" << endl;
    //Wilma W;
    Fred F;
    F.barney();
    return 0;
}