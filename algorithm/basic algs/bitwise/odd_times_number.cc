/*
功能：n个数，其中有且仅有两个数出现了奇数次，其余的数都出现了偶数次。
      用线性时间常数空间找出出现了奇数次的那两个数。
written by baoer on 2012-5-21
*/

#include <iostream>
#include <vector>
using namespace std;

//find 2 number which appear odd times
void FindOddNumber(const vector<int> &num)
{
    int sum = 0;
    for(int i=0; i<num.size(); i++)  //所有数求异或
    {
        sum ^= num[i];
    }

    if(sum == 0)
    {
        cout << "no such number" << endl;
    }
    else
    {
        int count = 0;
        int temp = sum;
        while(!(temp&1))  //得到最低一位1所在的位置
        {
            temp >>= 1;
            count++;
        }

        int a = 0;   //第一个数
        for(int i=0; i<num.size(); i++)
        {
            if((num[i]>>count)&1)    //根据第count位的值进行分组
            {
                a ^= num[i];
            }
        }
        int b = sum ^ a;   //第二个数
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
}

int main(void)
{
    int n;
    vector<int> num;

    cout << "input n: ";
    cin >> n;

    cout << "input " << n << " numbers, seperated by space" << endl;
    int v;
    for(int i=0; i<n; i++)
    {
        cin >> v;
        num.push_back(v);
    }

    FindOddNumber(num);

    return 0;
}
