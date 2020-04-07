# Exceeds time limit and/or space
class Solution:
    cache = {1: '0', 2: '01'}
    def kthGrammar(self, N: int, K: int) -> int:
        def helper(row):
            if row in self.cache:
                return self.cache[row]
            else:
                prev = helper(row-1)
                replace = ''
                for l in prev:
                    if l == '0': replace += '01'
                    else: replace += '10'
                self.cache[row] = replace
                return self.cache[row]
        string = helper(N)
        return int(string[K-1]) if K <= len(string) else None
