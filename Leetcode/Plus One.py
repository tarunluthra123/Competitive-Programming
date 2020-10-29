class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i = len(digits)-1
        digits[i] += 1
        carry = digits[i]//10
        digits[i]%=10
        i-=1
        while i>=0 and carry>0:
            digits[i] += carry
            carry = digits[i]//10
            digits[i]%=10
            i-=1
        if carry > 0:
            return [carry]+digits
        else:
            return digits