from collections import Counter
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2):
            dict_bigger = Counter(nums1)
            smaller_list = nums2
        else:
            dict_bigger = Counter(nums2)
            smaller_list = nums1
        intersection = []
        for num in smaller_list:
            if num in dict_bigger and dict_bigger[num] > 0:
                intersection.append(num)
                dict_bigger[num] -= 1
        return intersection

# without Counter module
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2):
            nums_bigger = nums1
            smaller_list = nums2
        else:
            nums_bigger = nums2
            smaller_list = nums1
        
        dict_bigger = dict()
        for num in nums_bigger:
            dict_bigger[num] = dict_bigger.get(num, 0) + 1
        
        intersection = []
        for num in smaller_list:
            if num in dict_bigger and dict_bigger[num] > 0:
                intersection.append(num)
                dict_bigger[num] -= 1
        return intersection
