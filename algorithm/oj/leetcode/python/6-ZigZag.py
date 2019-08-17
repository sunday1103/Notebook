'''
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
'''

class Solution(object):
    def convert1(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        zigzag = ["" for i in range(numRows)]
        i = 0
        flag = True
        for c in s:
            zigzag[i] += c
            if flag:
                i += 1
                if i == numRows:
                    i -= 2
                    flag = False
            else:
                if i == 0:
                    flag = True
                    i += 1
                else:
                    i -= 1

        re = ""
        for i in range(numRows):
            re = re + zigzag[i]

        return re

    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        zigzag = ["" for i in range(numRows)]
        i = 0
        flag = True
        for c in s:
            zigzag[i] += c
            if flag:
                i += 1
                if i == numRows:
                    i -= 2
                    flag = False
            else:
                if i == 0:
                    flag = True
                    i += 1
                else:
                    i -= 1

        return "".join(zigzag)

S = Solution()
S.convert("ABCDEF", 2)