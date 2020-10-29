class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        ans = []
        for i in sorted(intervals):
            if ans and i[0]<=ans[-1][1]:
                ans[-1][1] = max(ans[-1][1],i[1])
            else:
                ans.append(i)
        return ans