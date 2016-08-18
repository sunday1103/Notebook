#include <stdio.h>

struct A
{
    double a;
    int b;
    char h;
    int c;
    char d;
};

/* A 24 byte
aaaa
aaaa
bbbb
h***
cccc
d***
*/

#pragma pack(1)
struct B
{
    double a;
    int b;
    char h;
    int c;
    char d;
};
#pragma pack()

/* B 18 byte
aaaa
aaaa
bbbb
hccc
cd
*/

struct C
{
    double a;
    int b;
    char h;
    int c;
    char d;
    int e;
};

/* C 32 byte
aaaa
aaaa
bbbb
h***
cccc
d***
eeee
**** //这里补全是因为 double占8byte，需要对齐 8的倍数
*/

#pragma pack(8)
struct S1
{
    short a;
    long b;
};
/* S1 16 byte
aa**
****
bbbb
bbbb //注意，再64位下，long为8byte
*/

struct S2
{
    char c;
    struct S1 d;
    long long e; // VC6.0下可能要用__int64代替双long
};
/* S2 32 byte
c***
aa**
****
bbbb
bbbb //注意，再64位下，long为8byte
****
eeee
eeee
*/

#pragma pack()

int main()
{
    struct A a;
    struct B b;
    struct C c;
    printf("size of struct A %d \n", sizeof(a));
    printf("size of struct B %d \n", sizeof(b));
    printf("size of struct C %d \n", sizeof(c));

    struct S1 s1;
    struct S2 s2;

    printf("size of struct S1 %d \n", sizeof(s1));
    printf("size of struct S2 %d \n", sizeof(s2));

    printf("%p\n", sizeof(long));

    printf("%p\n", &a);
    printf("----------\n");
    printf("%p\n", &b);
    printf("----------\n");
    printf("%p\n", &c);
    printf("---------\n");
    printf("%p\n", &s1);
    printf("%p\n", &(s1.a));
    printf("%p\n", &(s1.b));
    printf("---------\n");
    printf("%p\n", &(s2));
    printf("%p\n", &(s2.c));
    printf("%p\n", &(s2.d));
    printf("%p\n", &(s2.e));

    printf("-------------\n");
    int aaa;
    int bbb;
    printf("%p\n", &aaa);
    printf("%p\n", &bbb);
    return 0;
}

/*
32 bit 下的输出 vs
1>      +---
1>   0  | a
1>   8  | b
1>  12  | h
1>      | <alignment member> (size=3)
1>  16  | c
1>  20  | d
1>      | <alignment member> (size=3)
1>      +---
1>
1>
1>
1>  class B size(18):
1>      +---
1>   0  | a
1>   8  | b
1>  12  | h
1>  13  | c
1>  17  | d
1>      +---
1>
1>
1>
1>  class C size(32):
1>      +---
1>   0  | a
1>   8  | b
1>  12  | h
1>      | <alignment member> (size=3)
1>  16  | c
1>  20  | d
1>      | <alignment member> (size=3)
1>  24  | e
1>      | <alignment member> (size=4)
1>      +---
1>
1>
1>
1>  class S1    size(8):
1>      +---
1>   0  | a
1>      | <alignment member> (size=2)
1>   4  | b
1>      +---
1>
1>
1>
1>  class S2    size(24):
1>      +---
1>   0  | c
1>      | <alignment member> (size=3)
1>   4  | S1 d
1>      | <alignment member> (size=4)
1>  16  | e
1>      +---
*/