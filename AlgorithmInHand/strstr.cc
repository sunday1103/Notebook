#include <cstring>
#include <iostream>
#include <string>
#include <vector>

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
                str = cr + 1;
                break;
            }
        if (*s == '\0')
            return cr;
    }
    return NULL;
}

int strStr_2(string haystack, string needle)
{
    if (haystack.length() < needle.length())
        return -1;
    if (needle.length() == 0)
        return 0;

    int M = needle.length();
    int R = 256;
    //int dfa[M][R];
    vector<vector<int> > dfa;
    dfa.resize(M);
    for (int i = 0; i < M; i++)
        dfa[i].resize(R);
    dfa[0][needle[0]] = 1;
    for (int X = 0, j = 1; j < M; j++)
    {
        for (int c = 0; c < R; c++)
            dfa[j][c] = dfa[X][c];
        dfa[j][needle[j]] = j + 1;
        X = dfa[X][needle[j]];
    }

    int i, j;
    int N = haystack.length();
    for (i = 0, j = 0; i < N && j < M; i++)
    {
        j = dfa[j][haystack[i]];
    }
    if (j == M)
        return i - M;
    else
        return -1;
}

int main(int argc, char **argv)
{
    string h("mississippi");
    string n("sipp");
    cout << strStr_2(h, n) << endl;

    //char s[100] = { "qwertyuiop" };
    //cout << s << endl;
    // cout << argv[1] << endl;
    // cout << strstr_1(s, argv[1]) << endl;
}
