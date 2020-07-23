class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int other_idx = 0;
        for (int i = 0; i < m + n; ++i) {
            if (other_idx < n) {
                if (nums1[i] > nums2[other_idx]) {
                    for (int j = nums1.length-2; j >= i; --j) {
                        nums1[j+1] = nums1[j];
                    }
                    nums1[i] = nums2[other_idx++];
                } else if (i >= m+other_idx) {
                    while (other_idx < n) nums1[i++] = nums2[other_idx++];
                }
            }
        }
        return;
    }
}
