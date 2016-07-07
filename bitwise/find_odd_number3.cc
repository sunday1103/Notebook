#include <stdio.h>
//得到第i位的二进制
#define isON(n, i) ((n)&1 << (i)) //位运算优先级高于&

// Author: 397090770
// E-mail: wyphao.2007@163.com
// 转载请注明出处

void findTheSingleNumber(int *arr, int size)
{
        int tempA = 0, tempB = 0;
        int countA = 0, countB = 0;
        int i = 0, j = 0;
        
    for (i = 0; i < 31; i++)
    { //32位平台上，int只有32位
                tempA = tempB = countA = countB = 0;
                for (j = 0; j < size; j++)
        { //遍历数组
                        if (isON(arr[j], i))
            {
                                tempA ^= arr[j];
                                countA++;
                            
            }
            else
            {
                                tempB ^= arr[j];
                                countB++;
                    
            
            }
                    
        }
                
        if (countA & 0x1)
        { //奇数
                        if (0 == tempB)
            {
                                continue;
                            
            }
            else
            {
                                printf("%d\n", tempA); //肯定是不同的数字
                                break;
                            
            }
                    
        }
        else
        {
                        if (0 == tempA)
            {
                                continue;
                            
            }
            else
            {
                                printf("%d\n", tempB);
                                break;
                            
            }
                    
        }
            
    }
        
}

int main()
{
        int arr[] = {
        /*1, 3, -9, 2, 1, 2, -10*/
        1, 2, 4, 5, 6, 4, 2};
        
    findTheSingleNumber(arr, sizeof(arr) / sizeof(arr[0]));
        return 0;
}
