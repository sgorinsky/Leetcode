class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if k == 0:
            return []
        num_counts = {}
        res = []
        for n in nums:
            num_counts[n] = 1 if n not in num_counts else num_counts[n]+1
        
        count_nums = {}
        highs = []

        for key, val in num_counts.items():
            if val not in count_nums:
                count_nums[val] = [key]
                highs.append(val)
            else:
                count_nums[val].append(key)
        
        highs.sort(reverse=True)
        for h in highs:
            i = 0
            while i < len(count_nums[h]) and len(res) < k:
                res.append(count_nums[h][i])
                i += 1
            
            if len(res) == k:
                break
        return res
