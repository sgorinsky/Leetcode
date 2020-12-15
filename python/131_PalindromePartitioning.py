class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def helper(start, curr):
            if start >= len(s):
                partitions.append(curr)
                return
            
            for i in range(start, len(s)):
                if s[start:i+1] == s[start:i+1][::-1]:
                    helper(i + 1, curr + [s[start:i+1]])
        
        partitions = []
        helper(0, [])
        return partitions
