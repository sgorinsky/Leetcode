class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int trail = 0;
        double sum = 0, high = -10001;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k) sum += nums[i];
            else {
                high = max(sum / ((double) k), high);
                sum = sum + nums[i] - nums[trail++];
            }
        }
        return max(sum / ((double) k), high);
    }
};
