'''Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
'''

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # 以第i个字符中心的最长回文子串长度
        # 或者以第i个字符和第i-1个字符为中心的最长回文字符串
        lens = [1]
        strs = [s[0]]
        lens_1 = [0]
        strs_1 = ['']
        for index in range(1, len(s)):
            i = 0
            while index - i >= 0 and index + i <= len(s) - 1:
                if s[index - i] != s[index + i]:
                    break
                i += 1
            i -= 1
            lens.append(i * 2 + 1)
            strs.append(s[index - i: index + i + 1])

            i = -1
            while index - 1 - i >= 0  and index + i <= len(s) - 1:
                if s[index - 1 - i] != s[index + i]:
                    break
                i += 1
            str_temp = ''
            if i > -1:
                i -= 1
                str_temp = s[index - 1 - i: index + i + 1]
            lens_1.append(i * 2 + 2)
            strs_1.append(str_temp)

        maxLen1 = max(lens)
        maxLen2 = max(lens_1)
        str_temp_re = ''
        if maxLen1 > maxLen2:
            str_temp_re = strs[lens.index(maxLen1)]
        else:
            str_temp_re = strs_1[lens_1.index(maxLen2)]

        return str_temp_re

S = Solution()
inputS = "abba"
S.longestPalindrome(inputS)