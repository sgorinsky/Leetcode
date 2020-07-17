class Solution:
    def hIndex(self, citations: List[int]) -> int:
        if not citations:
            return 0
        
        n = len(citations)
        left, right = 0, n-1
        
        while left <= right:
            mid = (left+right)>>1
            
            if citations[mid] == n-mid:
                return citations[mid]
            elif citations[mid] > n-mid:
                right = mid-1
            else:
                left = mid+1
                    
        return n-left
