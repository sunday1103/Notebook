'''
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
'''

class Solution(object):
    def twoSum1(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_backup = nums[:]
        nums.sort()
        head = 0
        tail = len(nums) - 1
        while head < tail:
            if nums[head] + nums[tail] == target:
                re = nums_backup.index(nums[head])
                if nums[head] == nums[tail]:
                    re1 = nums_backup.index(nums[tail], re + 1)
                else:
                    re1 = nums_backup.index(nums[tail])
                return [re, re1]

            if nums[head] + nums[tail] < target:
                head += 1

            if nums[head] + nums[tail] > target:
                tail -= 1

        return [-1, -1]

    def twoSum2(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in nums:
            if target - i == i:
                if nums.count(target - i) >= 2:
                    return [nums.index(i), nums.index(i, nums.index(i) + 1)]
                else:
                    continue
            if nums.count(target - i) == 1 :
                return [nums.index(i), nums.index(target - i)]

        return [-1,-1]

    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        for index, item in enumerate(nums):
            if target - item in dict:
                return [dict[target - item], index]
            dict[item] = index

        return []

nums = [-2,1,-3,4,-1,2,1,-5,4]

S = Solution()

n = S.twoSum(nums, 3)

print(n)