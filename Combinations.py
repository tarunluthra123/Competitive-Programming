class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        l = list(range(1,n+1))
        res = []
        for i in range((1<<n)):
            if bin(i).count('1')==k:
                j,p = 0,[]
                # print(i)
                while i>0:
                    if (i&1):
                        p += [l[j]]
                    j += 1
                    i = i>>1
                res += [p]
        
        return res
                        