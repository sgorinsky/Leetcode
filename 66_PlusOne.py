class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if not digits:
            return digits
        
        has_leading_zero = digits[0] == 0 and len(digits) > 1
        to_int = 0
        for i in range(len(digits)):
            to_int = to_int*10 + digits[i]
        
        to_int += 1
        res = []
        while to_int != 0:
            res = [to_int%10] + res
            to_int //= 10
        return res if not has_leading_zero else [0] + res

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if not digits:
            return [1]
        elif digits[-1] < 9:
            digits[-1] += 1
            return digits
        elif len(digits) == 1 and digits[0] == 9:
            return [1, 0]
        else:
            digits[-1] = 0
            digits[0:-1] = self.plusOne(digits[0:-1])
            return digits
