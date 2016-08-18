#include <cstring>
#include <iostream>

using namespace std;
size_t strlen_1(const char *str)
{
    int len = 0;
    while ((*str++) != '\0')
    {
        len++;
    }
    return len;
}

size_t strlen_2(const char *str)
{
    //assert(str == NULL);
    const char *p = str;
    while ((*p++) != '\0')
        return p - str;
}

int main(int argc, char **argv)
{
    char s[100];
    if (argc > 1)
    {
        cout << argv[1] << endl;
        strcpy(s, argv[1]);
        //    s = argv[1];
    }
    else
    {
        cin >> s;
    }
    cout << s << endl;
    cout << strlen_1(s) << endl;
    cout << s << endl;
    cout << strlen_2(s) << endl;
    cout << s << endl;
}
