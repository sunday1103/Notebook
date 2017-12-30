'''
Determine whether an integer is a palindrome. Do this without extra space.
'''
class Solution:
	def getNthNumer(self, x, n):
		"1234: The 0th numer is 4"
		return x // pow(10, n) % 10
	
	def getTotalNumer(self, x):
		"Get the Total Numer of x"
		n = 0
		while x != 0:
			x = x // 10
			n += 1
		return n
	
	def isPalindrome1(self, x):
		"""
		:type x: int
		:rtype: bool
		"""
		if x < 0:
			return False
		h = self.getTotalNumer(x) - 1
		l = 0
		while h >= l:
			if self.getNthNumer(x, h) != self.getNthNumer(x, l):
				return False
			h -= 1
			l += 1
		return True
		
	def isPalindrome(self, x):
		"""
		:type x: int
		:rtype: bool
		"""
		
		if x < 0:
			return False
		s = str(x)
		h = len(s) - 1
		l = 0
		while h >= l:
			if s[h] != s[l]:
				return False
			h -= 1
			l += 1
		return True
		
	
		
		
		
