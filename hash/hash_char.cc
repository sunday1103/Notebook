#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    char s1[10], s2[10];
    scanf("%s%s", s1, s2);
    printf("%s  %s \n", s1, s2);

    int i = 0;
    while (s1[i] != '\0')
    {
        cout << s1[i] << " " << (int)s1[i] << endl;
        i++;
    }
}