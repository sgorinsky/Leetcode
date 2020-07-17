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

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 0:
            return []
        num_dict = {}
        ans = set()
        for i in nums:
            num_dict[i] = 1 if i not in num_dict else num_dict[i]+1
            if num_dict[i] == len(nums) and num_dict[i] > 2:
                if nums[i] == 0:
                    ans.add((0,0,0))
                    return ans
        
        for i in range(len(nums)-2):
            for j in range(i+1, len(nums)-1):
                current_2fer = nums[i]+nums[j]
                if -current_2fer in num_dict:
                    if nums[i] != -current_2fer and nums[j] != -current_2fer:
                        ans.add(self.trips_destructure(nums[i], nums[j], -current_2fer))
                    elif num_dict[-current_2fer] != 1:
                        if nums[i] == nums[j] == 0:
                            if num_dict[0] > 2:
                                ans.add(self.trips_destructure(nums[i], nums[j], -current_2fer))
                        else:
                            ans.add(self.trips_destructure(nums[i], nums[j], -current_2fer))
        return ans
                
    def trips_destructure(self, a, b, c):
        trips = [a, b, c]
        trips.sort()
        return (trips[0], trips[1], trips[2])
