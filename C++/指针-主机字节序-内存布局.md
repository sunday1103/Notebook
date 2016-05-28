# 主机字节序
## 大端模式

Big-Endian(大端模式)：就是将数字高位字节放在内存的低地址，数字低字节放在内存的高地址，比如数字0x12 34 56 78(12是数字的高位字节，78是数字的低位字节)使用大端模式在内存中的表示为：
低地址 -----------》 高地址
0x12 | 0x34 | 0x56 | 0x78

## 小端模式

Little-Endian(小端模式)：就是将数字高位字节放在内存的高地址，数字低字节放在内存的低地址，比如数字0x12 34 56 78(12是数字的高位字节，78是数字的低位字节)使用小端模式在内存中的表示为：
低地址 ------------》 高地址
0x78 | 0x56 | 0x34 | 0x12

## 常见CPU的字节序

大端模式构架CPU： PowerPC、IBM、Sun

小端模式构架CPU： X86、DEC

注意：ARM即可以工作在大端模式，也可以工作在小端模式

## 判断方法
```c++
// http://hahaya.github.io/Big-Endian-and-Little-Endian/
/*
 *  方法1：通过将int强制转换成char单字节，因为强制转换成char能得到int的
 *          低地址部分，通过判断这个低地址部分来判断机器字节序
 *
 */
bool is_big_endian_1()
{
    int a = 0x1234;
    char b;
    b = *(char *)&a;
    if (0x12 == b)
        return true;
    return false;
}
/*
 *  方法2：利用联合体union的存放顺序是所有成员都从低地址开始存放，然后获取
 *          低地址部分判断机器字节序(关于union的妙用将会在后面的文字中介绍)
 *
 */
bool is_big_endian_2()
{
    union NUM {
        int a;
        char b;
    } num;
    num.a = 0x1234;
    if (0x12 == num.b)
        return true;
    return false;
}
```
