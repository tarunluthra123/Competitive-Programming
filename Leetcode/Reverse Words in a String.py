class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        r = s.split()
        r.reverse()
        ans = ' '.join(r)
        return ans
