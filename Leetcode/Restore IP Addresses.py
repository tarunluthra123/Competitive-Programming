class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        for i in range(1,4):
            for j in range(1,4):
                for k in range(1,4):
                    for l in range(1,4):
                        if i+j+k+l == len(s):
                            # print(i,j,k,l)
                            a = int(s[:i])
                            b = int(s[i:i+j])
                            c = int(s[i+j:i+j+k])
                            d = int(s[i+j+k:i+j+k+l])
                            # print(a,b,c,d)
                            if a<=255 and b<=255 and c<=255 and d<=255:
                                ans = ".".join(map(str,[a,b,c,d]))
                                # print(ans,len(ans))
                                if len(ans)==len(s)+3:
                                    res.append(ans)
        
        return res
                                