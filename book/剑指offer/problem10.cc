class Solution
{
  public:
    int NumberOf1(int n)
    {
        unsigned int i = 1;
        int num = 0;
        while (i)
        {
            if (n & i)
                num++;
            i = i << 1;
        }
        return num;
    }
};

/*
C++ C中，
 int a = 1;
a << n;
其中n 不能小于0 或者大于31，如果不符合就是未定义行为，在g++ 中是循环位移，
也就是 
a << 32 是 1
a << 33 是2
a << -1 是 a<< 31


为了移动32位，可以
a = a<< 31
a = a <<1
*/