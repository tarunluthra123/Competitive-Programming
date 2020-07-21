class Solution:
    def helper(self, candidates, target, s, i, ans):
        # print(i,s,ans)
        if s == target:
            self.res.add(tuple(ans))
        if s > target or i >= len(candidates):
            return
            return
        if s + candidates[i] <= target:
            self.helper(candidates, target, s +
                        candidates[i], i+1, ans + [candidates[i]])
        self.helper(candidates, target, s, i+1, ans)

    def combinationSum2(self, candidates, target: int):
        self.res = set()
        self.helper(sorted(candidates), target, 0, 0, [])
        return self.res
