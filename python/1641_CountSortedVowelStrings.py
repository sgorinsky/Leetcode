class Solution:
    def countVowelStrings(self, N: int) -> int:
        self.cache = {}
        def helper(n, vowels_left):
            if n == 1:
                return vowels_left
            elif vowels_left == 1:
                return 1
            elif (n, vowels_left) in self.cache:
                return self.cache[(n, vowels_left)]
            
            self.cache[(n, vowels_left)] = helper(n - 1, vowels_left) + helper(n, vowels_left - 1)
            return self.cache[(n, vowels_left)]
        return helper(N, 5)
