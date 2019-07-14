#include <string>
#include <iostream>

using namespace std;

/*聚合类：
1. 所有成员是public
2. 没有构造函数
3. 没有类内初始值
4. 没有基类，没有virtual函数
*/

/*聚合类可以使用成员初始值列表*/
struct data
{
    int a;
    string s;
    void print(){cout<<a<<" "<<s<<endl;}
};

int main()
{
    data d = {10, "sds"};
    d.print();
}

   
