class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        int res = 0;
        for (int n : nums) {
            if (counts.find(k - n) != counts.end() && counts[k - n] > 0) {
                res++;
                counts[k - n]--;
            } else {
                counts[n]++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, count = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) count++, left++, right--;
            else if (sum < k) left++;
            else right--;
        }
        return count;
    }
};
