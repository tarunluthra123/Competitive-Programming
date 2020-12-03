class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        s = list(s.split())
        if len(s)!=len(pattern):
            return False
        d = {}
        seen = set()
        for i in range(len(pattern)):
            p = pattern[i]
            q = s[i]
            if p in d:
                if q!=d[p]:
                    return False
            else:
                if q in d.values():
                    return False
                d[p] = q
                seen.add(q)

        return True
