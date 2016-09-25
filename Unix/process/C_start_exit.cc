/*
c程序的启动和退出
*/

#include <cstdlib>
#include <iostream>

using namespace std;

void f1()
{
    cout << "in f1 " << endl;
}

void f2()
{
    cout << "in f2 " << endl;
}

void f3(int a)
{
    cout << "in f3, a is " << a << endl;
}

int main()
{
    atexit(f1);
    atexit(f2);
    //atexit(f3(32)); //atexit 只能是不带参数的
    cout << "in main " << endl;
    return 0;
}
