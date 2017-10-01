
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxSum = nums[0]
        currSum = 0
        for i in nums:
            currSum += i
            if currSum > maxSum:
                maxSum = currSum
            if currSum < 0:
                currSum = 0

        return maxSum




nums = [-2,1,-3,4,-1,2,1,-5,4]

S = Solution()

n = S.maxSubArray(nums)

print(n)