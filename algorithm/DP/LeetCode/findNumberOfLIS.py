
# Input: [1,3,5,4,7]
# Output: 2
# Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].

class Solution():
    def findLengthOfLIS(self, nums):
        """
        寻找最长递增子串的长度
        :type nums: List[int]
        :rtype: int
        """
        '''
        子问题：以第i个数字结尾的最长子序列长度 F（i）
        转移：F(i) = max{ F(j) + 1} j = 0, 1, 2, ..., i - 1, and 第j个数字小于第i个数字
       '''
        L = [1]
        for i in range(1, len(nums)):
            max_length = 0
            for j in range(0, i):
                if nums[j] < nums[i]:
                    if max_length < L[j] + 1:
                        max_length = L[j] + 1
            L.append(max_length)

        return max(L)

    def findNumberOfLIS(self, nums):
        """
        寻找最长递增子串的个数
        :type nums: List[int]
        :rtype: int
        """
        '''
        子问题：以第i个数字结尾的最长子序列个数 N（i）, 最长子序列长度F(i)
        转移：F(i) = max{ F(j) + 1} j = 0, 1, 2, ..., i - 1, and 第j个数字小于第i个数字
        N(i)取上述等式获得最大值的j的N(j)之和，即：1. 第j个数字小于第i个数字 2. 使F取得最大值
        最后的处理：具有最长子序列的N之和
       '''
        L = [1]
        N = [1]

        for i in range(1, len(nums)):
            max_length = 1
            for j in range(0, i):
                if nums[j] < nums[i]:
                    if max_length < L[j] + 1:
                        max_length = L[j] + 1
            L.append(max_length)
            N.append(0)
            for j in range(0,i):
                if L[j] == L[i] - 1 and nums[j] < nums[i]:
                    N[i] += N[j]
            if L[i] - 1 == 0:
                N[i] = 1

        MaXL = max(L)
        MaXN = 0
        for i in range(len(nums)):
            if L[i] == MaXL:
                MaXN += N[i]

        print(L)
        print(N)
        return MaXN

S = Solution()
nums = [1,3,5,4,7]
nums = [2,2,2,2,2]
nums = [1,2,4,3,5,4,7,2]
re = S.findNumberOfLIS(nums)
print(re)


