#include <iostream>

using namespace std;

class A
{
  private:
    int a;
    void set(int c) { a = c; }
    virtual void f_p() { cout << "in A f_p()" << endl; }
  public:
    int get() { return a; }
    virtual void f() { cout << "111" << endl; }
};

class B : public A
{
  private:
    void f() { cout << "222" << endl; }
};

class C : public A
{
  public:
    virtual void f_in_c() { cout << "in f_in_c()" << endl; }
};

class D : public A
{
};

int *fff(int a, double b)
{
    cout << "fff\n";
}

int main()
{
    typedef void (*Fun)(void);
    Fun pFun = NULL;

    A a;
    B b;
    A *pa = &b;
    pa->f(); //即使B中f是private的，但是权限检查仅仅针对静态类型

    //权限控制
    cout << "";
    D d;
    d.f();
    // d.f_p(); // 不能够通过编译，因为f_p()为private
    pFun = (Fun) * (int *)(*(int *)(&d));
    pFun();

    C c;
    A *pa1 = &c;
    //pa1->f_in_c();
    long **pVtab = (long **)pa1;
    pFun = (Fun)pVtab[0][0];
    pFun();
    pFun = (Fun)pVtab[0][1];
    pFun();
    // pa1->f_in_c(); // 不能通过编译，因为静态类型A中没有 这个函数。
    pFun = (Fun)pVtab[0][2];
    pFun();

    C c1;
    A *pa2 = &c1;
    pFun = (Fun) * ((long *)(*(long *)(pa1)) + 2);
    //(Fun) * ((int *)(*(int *)(pa1)) + 2);
    //int **pVtab = (int **)pa1;
    pFun();

    typedef int *(*fptr)(int, double);
    fptr f1 = fff;
    f1(1, 2);

    int *pint = NULL;
    long *plong = NULL;
    cout << sizeof(pint) << endl;
    cout << sizeof(plong) << endl;

    int ss[3] = {1, 2, 3};
    cout << *ss << endl;
    cout << *(ss + 1) << endl;

    int ss1[2][3] = {1, 2, 3, 4, 5, 6};
    cout << *ss1[1] << endl;               // 4
    cout << ss1[1][2] << endl;             //6
    cout << **ss1 << endl;                 //1
    cout << **(ss1 + 1) << endl;           //4
    cout << *(*(ss1 + 1 * 1) + 2) << endl; //6
}
