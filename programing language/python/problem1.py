#题目：有四个数字：1、2、3、4，能组成多少个互不相同且无重复数字的三位数？各是多少？

nums = [1,2,3,4]

for i in nums:
    for j in nums:
        for k in nums:
            if(i != j and j != k and i != k):
                print(i,j,k)
