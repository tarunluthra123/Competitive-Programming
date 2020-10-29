class Solution:
    def countAndSay(self, n: int) -> str:
        def cns(str_):
            res = ''
            str_ += '#'
            c = 1
            for i in range(len(str_) - 1):
                if str_[i] == str_[i+1]:
                    c += 1
                    continue
                else:
                    res += str(c) + str_[i]
                    c = 1

            return res

        ans = "1"
        for i in range(n-1):
            ans = cns(ans)
        return ans
