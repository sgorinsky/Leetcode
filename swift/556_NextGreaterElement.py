class Solution:
    def nextGreaterElement(self, n: int) -> int:
        digits = deque()
        while n > 0:
            digits.appendleft(n % 10)
            n //= 10
        
        switched = False
        for i in range(len(digits) - 1, 0, -1):
            if digits[i - 1] < digits[i]:
                switched = True
                end = len(digits) - 1
                
                while digits[i - 1] >= digits[end]: end -= 1
                digits[i - 1], digits[end] = digits[end], digits[i - 1]
                
                j = len(digits) - 1
                while i < j:
                    digits[i], digits[j] = digits[j], digits[i]
                    i += 1
                    j -= 1
                break
        
        if not switched:
            return -1
        
        while digits:
            if n > 2147483647 / 10: return -1
            n *= 10
            n += digits.popleft();
        return n
            
