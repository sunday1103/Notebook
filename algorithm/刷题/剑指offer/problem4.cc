// length为牛客系统规定字符串输出的最大长度，固定为一个常数
#include <cstring>
#include <iostream>
#include <string>

class Solution {
 public:
  void replaceSpace(char *str, int length) {
    char *s = str;
    std::string mystring;
    while (*s != '\0') {
      if (*s != ' ') {
        mystring = mystring + *s;
      } else {
        mystring = mystring + "%20";
      }
      s++;
    }
    strcpy(str, mystring.c_str());
  }
};

int main() {
  Solution S;
  char str[] = "I am happy";
  S.replaceSpace(str, 100);
  std::cout << str << std::endl;
}