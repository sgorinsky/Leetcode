class Solution:
    def countPrimes(self, n: int) -> int:
        sieve, count = [True] * n, 0
        for i in range(2, n):
            if sieve[i]:
                j = 1
                while i*j < n:
                    sieve[i*j] = False
                    j += 1
                count += 1
        return count

class Solution:
    def countPrimes(self, n: int) -> int:
        sieve, count = [True] * n, 0
        for i in range(2, n):
            if sieve[i]:
                sieve[i:n:i] = [False for idx in range(i, n, i)]
                count += 1
        return count
