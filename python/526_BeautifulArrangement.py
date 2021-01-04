class Solution:
    def countArrangement(self, n: int) -> int:
        def backtrack(idx):
            nonlocal count
            if idx > n:
                count += 1
                return count
            
            for i in range(1, n + 1):
                if not visited[i] and (idx % i == 0 or i % idx == 0):
                    visited[i] = True
                    backtrack(idx + 1)
                    visited[i] = False
            
            return count
        
        count = 0
        visited = [False for _ in range(n + 1)]
        return backtrack(1)
