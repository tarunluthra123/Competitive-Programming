class Solution:
    def generate(self, s, open, close, n):
        if close == n:
            self.res.append(s)
            return
        if open < n:
            self.generate(s+'(', open+1, close, n)
        if close < open:
            self.generate(s+')', open, close+1, n)

    def generateParenthesis(self, n: int):
        self.res = []
        self.generate("", 0, 0, n)
        return self.res
