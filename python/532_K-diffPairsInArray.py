class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k < 0: return 0
        nums_set, pairs_set, count = set(), set(), 0
        
        for i, num in enumerate(nums):
            pair1, pair2 = [num-k, num], [num+k, num]
            pair1.sort()
            pair2.sort()
            if num-k in nums_set and not (pair1[0], pair1[1]) in pairs_set:
                count += 1
                pairs_set.add((pair1[0], pair1[1]))
            if num+k in nums_set and not (pair2[0], pair2[1]) in pairs_set:
                count += 1
                pairs_set.add((pair2[0], pair2[1]))
            nums_set.add(num)
        return count
