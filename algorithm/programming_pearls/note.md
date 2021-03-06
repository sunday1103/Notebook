# 编程珠玑笔记

## 第一章 开篇

### 常数时间初始化数组

**问题描述**

大数组初始化为0需要耗费大量时间，设计一种技术使第一次访问数组元素的时候将元素初始化为0.

**问题解决**

数据为

data[100]

使用辅助数组from[100]、to[100]、以及计数top（初始为0）

在访问数据元素i的时候，进行判断，如果满足下列2个条件，则表示该元素已经被初始化过：

- from[i] < top

- to[from[i]] == i

在初始化或者对元素赋值的时候，维护from、to、top三个变量：
```
from[i] = top
to[top] = i
top++
```

通过这样的方式，保证了不会由于随机数导致误判断数组元素已经初始化。

**证明**

1. 初始阶段，top为0，那么访问任意的元素位置i都不满足条件1，元素未被初始化，判断正确；

2. 在某一时刻，有未初始化的元素```i```

   1. 如果```from[i]```不满足条件1，那么这个元素肯定未被初始化，因为初始化的时候会设置```from[i] = top```，而top随后会+1，这样初始化的元素肯定满足条件1；
   2. 如果刚好随机数满足条件1，则```from[i] < top```，那么该数去索引```to```的元素```to[from[i]]```，当索引位置```i```的元素未被初始化时，```to[from[i]]```肯定不等于```i```（因为：如果未被初始化的元素也满足条件2，那么```to[from[i]]```就对应2个元素了，这显然是不成立的），这样条件2就不满足了。

   所以，对于未初始化的元素，肯定不满足条件1和条件2；

3. 而初始化的元素因为有上述赋值操作，肯定满足条件1和条件2。

**实现**

[代码实现]: ./1_sort/initArray.cpp

