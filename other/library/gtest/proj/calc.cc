#include <iostream>
#include "calc.h"

Calc::Calc(int a)
{
    state = a;
}

int Calc::add(int a, int b)
{
    return a + b;
}

int Calc::multi(int a, int b)
{
    return a * b;
}

int Calc::specficMulti(int a, int b)
{
    int output = multi(a, b);
    if (add(a, b) == 10)
    {
        output = 100;
    }

    return output;
}

//int main()
//{
//    std::cout << add(3, 10);
//}