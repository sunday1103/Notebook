#include <stdafx.h>
#include <stdbool.h>
#include <stdio.h>

struct foo1
{
    char *p;
    char c;
    long x;
};

struct foo2
{
    char c;      /* 1 byte */
    char pad[7]; /* 7 bytes */
    char *p;     /* 8 bytes */
    long x;      /* 8 bytes */
};

struct foo3
{
    char *p; /* 8 bytes */
    char c;  /* 1 byte */
};

struct foo4
{
    short s; /* 2 bytes */
    char c;  /* 1 byte */
};

struct foo5
{
    char c;
    struct foo5_inner
    {
        char *p;
        short x;
    } inner;
};

struct foo6
{
    short s;
    char c;
    int flip : 1;
    int nybble : 4;
    int septet : 7;
};

struct foo7
{
    int bigfield : 31;
    int littlefield : 1;
};

struct foo8
{
    int bigfield1 : 31;
    int littlefield1 : 1;
    int bigfield2 : 31;
    int littlefield2 : 1;
};

struct foo9
{
    int bigfield1 : 31;
    int bigfield2 : 31;
    int littlefield1 : 1;
    int littlefield2 : 1;
};

struct foo10
{
    char c;
    struct foo10 *p;
    short x;
};

struct foo11
{
    struct foo11 *p;
    short x;
    char c;
};

struct foo12
{
    struct foo12_inner
    {
        char *p;
        short x;
    } inner;
    char c;
};

int main()
{
    printf("sizeof(char *)        = %zu\n", sizeof(char *));
    printf("sizeof(long)          = %zu\n", sizeof(long));
    printf("sizeof(int)           = %zu\n", sizeof(int));
    printf("sizeof(short)         = %zu\n", sizeof(short));
    printf("sizeof(char)          = %zu\n", sizeof(char));
    printf("sizeof(float)         = %zu\n", sizeof(float));
    printf("sizeof(double)        = %zu\n", sizeof(double));
    printf("sizeof(struct foo1)   = %zu\n", sizeof(struct foo1));
    printf("sizeof(struct foo2)   = %zu\n", sizeof(struct foo2));
    printf("sizeof(struct foo3)   = %zu\n", sizeof(struct foo3));
    printf("sizeof(struct foo4)   = %zu\n", sizeof(struct foo4));
    printf("sizeof(struct foo5)   = %zu\n", sizeof(struct foo5));
    printf("sizeof(struct foo6)   = %zu\n", sizeof(struct foo6));
    printf("sizeof(struct foo7)   = %zu\n", sizeof(struct foo7));
    printf("sizeof(struct foo8)   = %zu\n", sizeof(struct foo8));
    printf("sizeof(struct foo9)   = %zu\n", sizeof(struct foo9));
    printf("sizeof(struct foo10)   = %zu\n", sizeof(struct foo10));
    printf("sizeof(struct foo11)   = %zu\n", sizeof(struct foo11));
    printf("sizeof(struct foo12)   = %zu\n", sizeof(struct foo12));
}

/*
class foo1	size(12):
1>  	+---
1>   0	| p
1>   4	| c
1>    	| <alignment member> (size=3)
1>   8	| x
1>  	+---
1>
1>
1>
1>  class foo2	size(16):
1>  	+---
1>   0	| c
1>   1	| pad
1>   8	| p
1>  12	| x
1>  	+---
1>
1>
1>
1>  class foo3	size(8):
1>  	+---
1>   0	| p
1>   4	| c
1>    	| <alignment member> (size=3)
1>  	+---
1>
1>
1>
1>  class foo4	size(4):
1>  	+---
1>   0	| s
1>   2	| c
1>    	| <alignment member> (size=1)
1>  	+---
1>
1>
1>
1>  class foo5_inner	size(8):
1>  	+---
1>   0	| p
1>   4	| x
1>    	| <alignment member> (size=2)
1>  	+---
1>
1>
1>
1>  class foo5	size(12):
1>  	+---
1>   0	| c
1>    	| <alignment member> (size=3)
1>   4	| foo5_inner inner
1>  	+---
1>
1>
1>
1>  class foo6	size(8):
1>  	+---
1>   0	| s
1>   2	| c
1>    	| <alignment member> (size=1)
1>   4.	| flip (bitstart=0,nbits=1)
1>   4.	| nybble (bitstart=1,nbits=4)
1>   4.	| septet (bitstart=5,nbits=7)
1>  	+---
1>
1>
1>
1>  class foo7	size(4):
1>  	+---
1>   0.	| bigfield (bitstart=0,nbits=31)
1>   0.	| littlefield (bitstart=31,nbits=1)
1>  	+---
1>
1>
1>
1>  class foo8	size(8):
1>  	+---
1>   0.	| bigfield1 (bitstart=0,nbits=31)
1>   0.	| littlefield1 (bitstart=31,nbits=1)
1>   4.	| bigfield2 (bitstart=0,nbits=31)
1>   4.	| littlefield2 (bitstart=31,nbits=1)
1>  	+---
1>
1>
1>
1>  class foo9	size(12):
1>  	+---
1>   0.	| bigfield1 (bitstart=0,nbits=31)
1>   4.	| bigfield2 (bitstart=0,nbits=31)
1>   4.	| littlefield1 (bitstart=31,nbits=1)
1>   8.	| littlefield2 (bitstart=0,nbits=1)
1>  	+---
1>
1>
1>
1>  class foo10	size(12):
1>  	+---
1>   0	| c
1>    	| <alignment member> (size=3)
1>   4	| p
1>   8	| x
1>    	| <alignment member> (size=2)
1>  	+---
1>
1>
1>
1>  class foo11	size(8):
1>  	+---
1>   0	| p
1>   4	| x
1>   6	| c
1>    	| <alignment member> (size=1)
1>  	+---
1>
1>
1>
1>  class foo12_inner	size(8):
1>  	+---
1>   0	| p
1>   4	| x
1>    	| <alignment member> (size=2)
1>  	+---
1>
1>
1>
1>  class foo12	size(12):
1>  	+---
1>   0	| foo12_inner inner
1>   8	| c
1>    	| <alignment member> (size=3)
1>  	+---
1>
*/