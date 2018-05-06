'''
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
'''

class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            length = 0
        else:
            length = min([len(i) for i in strs])
        re = ''
        for i in range(length):
            for s in strs[1:]:
                if strs[0][i] != s[i]:
                    return re
            re += strs[0][i]
        return re
    
S = Solution()
print(S.longestCommonPrefix(["flower","flow","floww"]))