#include <iomanip>
#include <iostream>
#include <map>

using namespace std;
class data
{
  public:
    int x;
    double b;
    char c;
    int d;
    data();
    int f();
};
data::data()
{
    c = 'A';
    x = 1;
}

// http://hahaya.github.io/Big-Endian-and-Little-Endian/
/*
 *  方法1：通过将int强制转换成char单字节，因为强制转换成char能得到int的
 *          低地址部分，通过判断这个低地址部分来判断机器字节序
 *
 */
bool is_big_endian_1()
{
    int a = 0x1234;
    char b;
    b = *(char *)&a;
    if (0x12 == b)
        return true;
    return false;
}
/*
 *  方法2：利用联合体union的存放顺序是所有成员都从低地址开始存放，然后获取
 *          低地址部分判断机器字节序(关于union的妙用将会在后面的文字中介绍)
 *
 */
bool is_big_endian_2()
{
    union NUM {
        int a;
        char b;
    } num;
    num.a = 0x1234;
    if (0x12 == num.b)
        return true;
    return false;
}

int main()
{
    data s;
    cout << "s address\t" << &s << endl;
    cout << "s.x address\t" << &(s.x) << endl;
    cout << "s.b address\t" << &(s.b) << endl;
    cout << "s.c address\t" << (void *)&(s.c) << endl;
    cout << "s.d address\t" << &(s.d) << endl;
    cout << "sizeof s\t" << sizeof(s) << endl;
    cout << "sizeof s.x\t" << sizeof(s.x) << endl;
    cout << "sizeof s.b\t" << sizeof(s.b) << endl;
    cout << "sizeof s.c\t" << sizeof(s.c) << endl;
    cout << "sizeof s.d\t" << sizeof(s.d) << endl;
    cout << "big end OR littel end" << endl;
    //============= using (char) to
    int a = 0x1234;
    char b = (char)a;
    cout << " int \t" << hex << a << endl;
    cout << " char \t" << hex << b << endl;
    // -----
    cout << is_big_endian_1() << endl;

    cin >> a;
}
