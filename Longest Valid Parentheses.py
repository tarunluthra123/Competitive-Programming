class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n, ans, mx = len(s), 0, 0
        if n == 0:
            return 0
        stack = []
        for i in range(n):
            if s[i] == '(':
                stack.append(mx)
                mx = 0
            else:
                if len(stack) == 0:
                    mx = 0
                else:
                    mx += stack[-1] + 2
                    stack.pop()
                    ans = max(ans, mx)

        return ans
