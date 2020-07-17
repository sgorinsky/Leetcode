class Solution:
    def findLHS(self, nums: List[int]) -> int:
        num_counts = {}
        for n in nums:
            num_counts[n] = 1 if n not in num_counts else num_counts[n]+1
            
        high = 0
        for k, v in num_counts.items():
            if k-1 in num_counts:
                high = max(high, v+num_counts[k-1])
            
            if k+1 in num_counts:
                high = max(high, v+num_counts[k+1])
        
        return high
