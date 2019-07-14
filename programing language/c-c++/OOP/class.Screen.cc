#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Screen
{
public:
    /*
    1. 类型成员：这个类型也接受类型说明符的控制，是属于对外接口的一部分；
    2. 在使用前，需要先有类型定义，也就是下面的pos cursor需要放在这个定义后面；
    3. C++11可以使用：using pos = string::size_type;
    4. 如果类外部有这个类型名，那么这里就不能重复定义。和成员变量名不一样，变量名可以重载。
    */
    typedef string::size_type pos;

    Screen() = default;
    Screen(pos h, pos w, char c): height(h), width(w), contens(h*w, c) {}
    /*隐式内联*/
    char get() const {return contens[cursor];}
    /*显式内联*/
    inline char get(pos h, pos w) const;
    Screen &move(pos r, pos c);

    /*根据是否是const成员函数可以进行函数重载。当常量成员调用display的时候优先使用常量版本。*/
    Screen &display(ostream &os) {do_display(os); return *this;}
    const Screen &display(ostream &os) const {do_display(os); return *this;}

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    string contens;
    /*mutable修饰成员变量：可变数据成员。即使是const函数也可以改变该成员的值。*/
    mutable size_t access_ctr;

    void do_display(ostream &os) const {os << contens;}
};

/*
和inline函数一样，inline成员函数也应该与相应的类定义在同一个**头文件**中
*/

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contens[row + c];
}


class Windows_mgr
{
private:
    /*C++11 对数据成员提供类内初始值
      C++11 列表初始化： vector<int> a{1,2}; vector<int> a = {1,2}
    */
    vector<Screen> screens{Screen(24, 80, ' ')};
};

int main(int argc, char const *argv[])
{
    Screen S(4, 5, 'a');
    S.display(cout);
    return 0;
}
