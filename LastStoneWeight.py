class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        while len(stones) > 1:
            stones.sort()
            diff = stones[-1] - stones[-2]
            del stones[-1:-3:-1]
            if diff != 0: stones.append(diff)
        return stones[0] if stones else 0

# Faster solution that sorts once and binary searches insertion point for difference of two largest stones
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort()
        def findInsertionPoint(entry):
            left, right = 0, len(stones)
            while left < right:
                mid = (left + right) >> 1
                if stones[mid] == entry:
                    return mid
                elif stones[mid] > entry:
                    right = mid - 1
                else:
                    left = mid + 1
            return left
            
        while len(stones) > 1:
            diff = stones[-1] - stones[-2]
            del stones[-1:-3:-1]
            if diff != 0: 
                insert_at = findInsertionPoint(diff)
                # binary search may return end of array: insert method doesn't append
                if insert_at == len(stones): 
                    stones.append(diff)
                else:
                    # binary search may return index where stones[index] < diff by 1 index
                    #   that would unsort array
                    if stones[insert_at] < diff: insert_at += 1
                    stones.insert(insert_at, diff)
        return stones[0] if stones else 0
