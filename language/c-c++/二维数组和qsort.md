# qsort

## 函数原型和基本例子

> `void qsort (void* base, size_t num, size_t size,int (*compar)(const void*,const void*))`
>
> 将base所指的数据（数据个数为num，每个数据大小为size）排序，排序的依据是cmpar函数描述的规则。
> `int compar (const void* p1, const void* p2);`
>  - 当p1指向的数据小于p2时，返回 <0
>  - 当p1指向的数据等于p2时，返回 =0
>  - 当p1指向的数据大于p2时，返回 >0

基本例子如下：(cplusplus)

```c
/* qsort example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main ()
{
  int n;
  qsort (values, 6, sizeof(int), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
  return 0;
}

Output:

10 20 25 40 90 100
```

## compare函数

compare函数参数是void指针类型，在使用参数的时候：

1. 确认指针的数据类型