#include <cstring>
#include <iostream>

using namespace std;
char *strstr_1(char *str, const char *str1)
{
    const char *s = str1;
    char *cr = NULL;
    while (*str != '\0')
    {
        if (*str++ != *s)
            continue;
        cr = str--;
        while (*s != '\0')
            if (*++str != *++s)
            {
                s = str1;
                break;
            }
        if (*s == '\0')
            return cr;
    }
    return NULL;
}

int main(int argc, char **argv)
{
    char s[100] = {"qwertyuiop"};
    cout << s << endl;
    cout << argv[1] << endl;
    cout << strstr_1(s, argv[1]) << endl;
}
