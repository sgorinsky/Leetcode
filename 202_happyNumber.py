# recent solution for 30 day leetcode challenge e
class Solution:
    def isHappy(self, n: int) -> bool:
        if n < 0: return False
        
        prior_nums = set()
        while n != 1:
            curr = 0
            while n != 0:
                curr += (n % 10)**2
                n //= 10
            n = curr
            if n in prior_nums: return False
            prior_nums.add(n)
        return True

class Solution:
    def isHappy(self, n: int) -> bool:
        original, count = n, 0
        loop_set = {}
        while original != 1:
            loop_set[original] = 1 if original not in loop_set else 2
            current = 0
            if original == 0 or loop_set[original] == 2:
                return False
            elif original == 1:
                return True
            else:
                count += 1
                while original != 0:
                    current, original  = current + (original % 10)**2, original // 10
                original = current
        return True
