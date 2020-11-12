class Solution:
    def twoSumLessThanK(self, A: List[int], K: int) -> int:
        closest_sum = -1
        counts = [0 for _ in range(1001)]
        
        for n in A: counts[n] += 1
            
        left, right = 1, 1000
        while left < right:
            cand_sum = left + right
            has_count = counts[left] > 0 and counts[right] > 0
            if cand_sum >= K or counts[right] == 0:
                right -= 1
            else:
                if counts[left] > 0:
                    closest_sum = max(cand_sum, closest_sum)
                left += 1
        
        return closest_sum
