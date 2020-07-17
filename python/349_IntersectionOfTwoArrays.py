class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2):
            big_set = set(nums1)
            smaller_list = nums2
        else:
            big_set = set(nums2)
            smaller_list = nums1
        intersection = set()
        for num in smaller_list:
            if num in big_set:
                intersection.add(num)
        return intersection

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        set1, set2 = set(nums1), set(nums2)
        return list(set2 & set1)
