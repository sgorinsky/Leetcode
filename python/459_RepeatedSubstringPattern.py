class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        N = len(s)
        if N <= 1:
            return False
        
        for i in range(2, N+1):
            if N % i == 0:
                divisor = N // i
                first = s[0:divisor]
                equal_substrings = True
                
                for j in range(1, i):
                    if s[j*divisor:(j+1)*divisor] != first:
                        equal_substrings = False
                        break
                if equal_substrings:
                    print(i)
                    return True
        return False
