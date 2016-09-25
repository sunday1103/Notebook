#include <cstring>
#include <iostream>

using namespace std;
char *strcpy_1(char *str, const char *str1)
{
    //assert (str!=NULL && str1!=NULL)
    char *orignal = str;
    while (*str1 != '\0')
    {
        *str++ = *str1++;
    }
    *str = '\0';
    return orignal;
}

int main(int argc, char **argv)
{
    char s[100] = {"qqqqq"};
    cout << s << endl;
    cout << argv[1] << endl;
    cout << strcpy_1(s, argv[1]) << endl;
    cout << s << endl;
}

/*
要用一个临时变量保存目的串的首地址，最后返回这个首地址。

函数返回 char* 的目的是为了支持链式表达式，即strcpy可以作为其他函数的实参。
*/
