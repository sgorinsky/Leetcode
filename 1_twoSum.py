def twoSum(nums: List[int], target: int) -> List[int]:
        ns = {}
        
        for i in range(len(nums)):
            current = nums[i]
            
            if (target-current) in ns:
                return [ns[target-current], i]
            if current not in ns:
                ns[current] = i
        
        return [0, 6] # if each set of nums has a solution, we should never get here
