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
