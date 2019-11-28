def threeSum(nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = set()
        for i in range(n):
            left = i+1
            right= n-1
            current = nums[i]
            while left < right:
                if current + nums[left] + nums[right] == 0:
                    ans.add((current,nums[left],nums[right]))
                    left += 1
                    right -= 1
                elif current + nums[left] + nums[right] > 0:
                    right -= 1
                else:
                    left += 1
        return ans
