class Solution:
    def romanToInt(self, s: str) -> int:
        d = {}
        d['I'] = 1
        d['V'] = 5
        d['X'] = 10
        d['L'] = 50
        d['C'] = 100
        d['D'] = 500
        d['M'] = 1000
        res = 0
        i = 1
        while i < len(s):
            if d[s[i-1]] >= d[s[i]]:
                res += d[s[i-1]]
            else:
                res -= d[s[i-1]]
            i += 1
        res += d[s[i-1]]
        return res
