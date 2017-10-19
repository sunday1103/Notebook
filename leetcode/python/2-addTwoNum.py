'''
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
'''

# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None
# 3 4 2 1
#   4 2 1

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l3 = ListNode(0)
        re = l3
        r = 0
        while l1 != None or l2 != None or r != 0:
            a = 0
            b = 0
            if l1 != None:
                a = l1.val
                l1 = l1.next
            if l2 != None:
                b = l2.val
                l2 = l2.next
            c = a + b + r
            if c >= 10:
                c = c - 10
                r = 1
            else:
                r = 0
            l3.next = ListNode(c)
            l3 = l3.next

        return re.next

