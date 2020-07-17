def threeSumClosest(nums, target) -> int:
        nums.sort()
        current_best = [1000000, 10]
        n = len(nums)
        for i in range(n-1):
            left = i+1
            right = n-1
            x = nums[i]
            while left < right:
                current_sum = x + nums[left] + nums[right]
                if current_sum == target:
                    return current_sum
                elif x + nums[left] + nums[right] > target:
                    right -= 1
                else:
                    left += 1
                if abs(target-current_sum) < current_best[0]: 
                    current_best = [abs(target-current_sum), current_sum]
        return current_best[1]
print(threeSumClosest([1,2,7,11], 20))
