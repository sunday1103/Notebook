#include "string"
#include "iostream"

using namespace std;

class Screen
{
public:
    /*
    1. 类型成员：这个类型也接受类型说明符的控制，是属于对外接口的一部分；
    2. 在使用前，需要现有类型定义，也就是下面的pos cursor需要放在这个定义后面；
    3. C++11可以使用：using pos = string::size_type;
    */
    typedef string::size_type pos;
private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    string contens;
}