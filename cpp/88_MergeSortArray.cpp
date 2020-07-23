class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = 0;
        for (int i = 0; i < n+m; ++i) {
            if (idx < n) {
                if (nums1[i] > nums2[idx]) {
                    for (int j = n+m-2; j >= i; --j) nums1[j+1] = nums1[j];
                    nums1[i] = nums2[idx++];
                } else if (i >= m+idx) {
                    while (idx < n) nums1[i++] = nums2[idx++];
                }
            } else {
                return;
            }
        }
    }
};
