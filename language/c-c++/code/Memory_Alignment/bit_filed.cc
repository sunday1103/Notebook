#include <iostream>
#include <memory.h>
using namespace std;
struct A
{
    int a : 5;
    int b : 3;
};
int main(void)
{
    char str[100] = "0134324324afsadfsdlfjlsdjfl";
    struct A d;
    memcpy(&d, str, sizeof(A));
    cout << sizeof(A) << endl;
    cout << d.a << endl;
    cout << d.b << endl;
    return 0;
}