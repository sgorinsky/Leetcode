class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        # N is power of 2, there are 2^(N-1) entries in a row, want to find kth index
        if N == 1:
            return 0
        elif N == 2:
            return 0 if K == 1 else 1
        else:
            # General case:
            if K % 2 == 0:

                # even index of current level is opposite of parent level's [(K+1)//2]
                return 0 if self.kthGrammar(N-1, (K+1)//2) else 1
            else:
                # odd index of current level is the same as parent level's [(K+1)//2]
                return 1 if self.kthGrammar(N-1, (K+1)//2) else 0
