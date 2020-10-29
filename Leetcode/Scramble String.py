class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if s1==s2:
            return True
        if sorted(s1) != sorted(s2):
            return False
        
        n = len(s1)
        
        for i in range(1,n):
            if self.isScramble(s1[0:i],s2[0:i]) and self.isScramble(s1[i:],s2[i:]):
                return True
            if self.isScramble(s1[0:i],s2[n-i:]) and self.isScramble(s1[i:],s2[0:n-i]):
                return True
            
        return False