#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a[2] = {1, 4};
    cout << a << " " << a + 1 << " " << &a + 1 << endl;
    int *p = a;
    printf("%d %d", *p + 1, *(p++));

    const int cint = 1;
    int cint2 = cint;

    int aa[] = {1, 2, 0, 2, 1};

    cout << aa << " " << &aa << endl;
    cout << sizeof(aa) << " " << sizeof(&aa) << endl;

    cout << (bool)((long)aa == (long)&aa) << endl;

    // const char *p1 = "dsjsj";
    // p1 + 1 = 's';
}