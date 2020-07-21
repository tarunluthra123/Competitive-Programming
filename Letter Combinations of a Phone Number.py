class Solution:
    def keypad(self, inp, out):
        if len(inp) == 0:
            if len(out) > 0:
                self.res.append(out)
            return

        r = int(inp[0])
        for i in range(len(self.phone[r])):
            ch = self.phone[r][i]
            self.keypad(inp[1:], out+ch)

    def letterCombinations(self, s: str):
        self.phone = ["", "", "abc", "def", "ghi",
                      "jkl", "mno", "pqrs", "tuv", "wxyz"]
        self.res = []
        self.keypad(s, "")
        return self.res
