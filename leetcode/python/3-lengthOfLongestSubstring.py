'''
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

子问题： 以某个字符结尾的最长子串 L_n
子问题递推：
下一个字符如果在上一个字符结尾的子串内出现，那么以该字符结尾的最长子串就是
该字符出现上一个位置的下一个字符一直到该字符。
比如
输入dvdf
以v结尾的最长子串是dv，现在处理下一个d，d出现在上一个子串中，所以以这个d为结尾的最长子串是vd

问题解：所有字符结尾的最长子串中的最大值。

'''


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        lastLongestStr = ""
        lastLen = 0
        maxLen = 0
        for item in s:
            if item in lastLongestStr:
                s = lastLongestStr.index(item)
                lastLongestStr = lastLongestStr[s + 1:] + item
                lastLen = len(lastLongestStr)
            else:
                lastLongestStr += item
                lastLen += 1
                if maxLen < lastLen:
                    maxLen = lastLen

        return maxLen

S = Solution()
r = S.lengthOfLongestSubstring("bpfbhmipx")
print(r)