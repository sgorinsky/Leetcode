class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        
        if (nums.empty() || nums[right] != target) return res;
        res[0] = right;
        left = right, right = nums.size() - 1;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        res[1] = nums[right] == target ? right : right - 1;
        return res;
    }
};
