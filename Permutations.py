class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.ans = set()
        self.helper(nums, [])
        return self.ans

    def helper(self, inp, out):
        if len(inp) == 0:
            self.ans.add(tuple(out))
            return

        for i in range(len(inp)):
            ros = inp[0:i] + inp[i + 1:]
            self.helper(ros, out+[inp[i]])
