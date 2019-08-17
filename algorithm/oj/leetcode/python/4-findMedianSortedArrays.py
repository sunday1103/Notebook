
'''
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

1 2 3 5 6 7
2 3 4 6 8

'''

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        i = 0
        j = 0
        nums1IsOver = False
        nums2IsOver = False
        if i == len(nums1):
            nums1IsOver = True
        if j == len(nums2):
            nums2IsOver = True

        merged = []
        while True:
            if nums1IsOver:
                merged = merged + nums2[j:]
                break
            if nums2IsOver:
                merged = merged + nums1[i:]
                break


            if nums1[i] < nums2[j]:
                merged.append(nums1[i])
                i += 1
                if i == len(nums1):
                    nums1IsOver = True
            else:
                merged.append(nums2[j])
                j += 1
                if j == len(nums2):
                    nums2IsOver = True

        re = 0
        if len(merged) % 2 == 0:
            re = merged[len(merged) // 2] + merged[len(merged) // 2 - 1]
            re = re / 2.0
        else:
            re = merged[len(merged) // 2]
        return re

a = [1, 3]
b = [2]

S = Solution()
S.findMedianSortedArrays(a,b)

