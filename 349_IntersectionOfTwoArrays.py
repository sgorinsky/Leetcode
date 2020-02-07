class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        bigger_list = len(nums1) > len(nums2)
        big_set = set(nums1) if bigger_list else set(nums2)
        smaller_list = nums2 if bigger_list else nums1
        intersection = set()
        for num in smaller_list:
            if num in big_set:
                intersection.add(num)
        return intersection
