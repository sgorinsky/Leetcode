class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return split(nums, 0, nums.size() - 1);
    }
    
    vector<int> split(vector<int>& nums, int start, int end) {
        if (start >= end) return {nums[start]};
        
        vector<int> first_half = split(nums, start, (start + end) >> 1);
        vector<int> second_half = split(nums, (start + end) / 2 + 1, end);
        
        return sortTwoArrays(first_half, second_half);
    }
    
    vector<int> sortTwoArrays(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int left = 0, right = 0;
        while (left < a.size() || right < b.size()) {
            if (right >= b.size() || (left < a.size() && a[left] < b[right])) {
                res.push_back(a[left++]);
            } else {
                res.push_back(b[right++]);
            }
        }
        return res;
    }
};
