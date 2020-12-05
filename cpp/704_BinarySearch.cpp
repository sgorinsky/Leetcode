class Solution {
public:
    int search(vector<int>& nums, int target) {
        return split(nums, target, 0, nums.size() - 1);
    }
    
    int split(vector<int>& nums, int target, int left, int right) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return split(nums, target, left, mid - 1);
        else return split(nums, target, mid + 1, right);
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};
