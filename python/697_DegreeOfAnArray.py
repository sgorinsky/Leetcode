class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int: 
        if not nums:
            return 0
        
        # num_dict[number] = [frequency_of_number, [start_idx, end_idx]]
        num_dict, highest_frequency, furthest_distance = {}, 0, 100000000
        
        for i in range(len(nums)):
            if nums[i] in num_dict:
                num_dict[nums[i]][0] += 1
                num_dict[nums[i]][1][-1] = i
            else:
                num_dict[nums[i]] = [1, [i, i]]
        
        for freq,indices in num_dict.values():
            if freq > highest_frequency:
                furthest_distance = indices[-1] - indices[0] + 1
                highest_frequency = freq
            elif freq == highest_frequency and indices[-1] - indices[0] + 1 < furthest_distance:
                    furthest_distance = indices[-1] - indices[0] + 1
        return furthest_distance
