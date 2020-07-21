class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c in ['(', '[', '{']:
                stack.append(c)
            elif c == ')' and len(stack) > 0:
                if stack[len(stack)-1] == '(':
                    stack.pop()
                else:
                    return False
            elif c == ']' and len(stack) > 0:
                if stack[len(stack)-1] == '[':
                    stack.pop()
                else:
                    return False
            elif c == '}' and len(stack) > 0:
                if stack[len(stack)-1] == '{':
                    stack.pop()
                else:
                    return False
            else:
                return False

        return len(stack) == 0
