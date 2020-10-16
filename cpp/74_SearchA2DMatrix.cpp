class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (vector<int>& row : matrix) {
            if (binary_search(row, target)) return true;
        }
        return false;
    }
    
    bool binary_search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};
