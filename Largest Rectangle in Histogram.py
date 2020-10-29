class Solution:
    def largestRectangleArea(self, a) -> int:
        if len(a)==0:
            return 0
        stack = []
        maxArea = 0
        n = len(a)
        for i in range(len(a)):
            while len(stack)>0 and a[i]<a[stack[-1]]:
                x = stack[-1]
                stack.pop()
                if len(stack)==0:
                    area = a[x]*i
                else:
                    area = a[x]*(i-stack[-1]-1)
                maxArea = max(maxArea, area)
                        
            stack.append(i)
        
        while len(stack)>0:
            area,x = 0, stack[-1]
            stack.pop()
            if len(stack)==0:
                area = a[x]*n
            else:
                area = a[x]*(n-stack[-1]-1)
            maxArea = max(maxArea, area)
            
        return maxArea
        
        