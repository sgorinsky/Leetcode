class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;
        m--, n--;
        
        while (idx >= 0) {
            if (m >= 0 && n >= 0) {
                nums1[idx] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
            } else {
                nums1[idx] = n >= 0 ? nums2[n--] : nums1[m--];
            }
            idx--;
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = n+m-1;
        m--, n--;
        while (idx >= 0) {
            if (n < 0 && m < 0) {
                return;
            } else if (n >= 0 && m >= 0) {
                nums1[idx--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
            } else {
                nums1[idx--] = m >= 0 ? nums1[m--] : nums2[n--];
            }
        }
    }
};

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
