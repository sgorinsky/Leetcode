class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        divisors = []
        root = floor(sqrt(n)) # sqrt is inflection pt all other divisors are made with ones before it
        for x in range(1, root + 1):
            if n % x == 0:
                k -= 1
                divisors.append(x)
                if k == 0:
                    return x
        
        if root * root == n: k += 1
        return n // divisors[len(divisors) - k] if k <= len(divisors) else -1
        
        
# [1, 2, 3, 4, 6] [9, 12, 18, 36]
