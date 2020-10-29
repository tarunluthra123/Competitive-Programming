class Solution:
    def helper(self, candidates, target, s, i, ans):
        if s > target or i >= len(candidates):
            return
        if s == target:
            self.res.append(ans)
            return
        if s + candidates[i] <= target:
            self.helper(candidates, target, s +
                        candidates[i], i, ans + [candidates[i]])
        self.helper(candidates, target, s, i+1, ans)

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.res = []
        self.helper(candidates, target, 0, 0, [])
        return self.res
