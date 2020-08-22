class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, zero = -1, high = 0, N = nums.size();
        
        for (int i = 0; i < N; ++i) {
            if (nums[i] == 0) {
                if (zero >= 0) {
                    left = zero + 1;
                }
                zero = i;
            }
            high = max(high, i - left + 1);
        }
        return high;
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<vector<int>> intervals = {};
        bool ones = false;
        
        vector<int> curr = {};
        for (int i = 0; i < nums.size(); ++i) {
            if (!ones && nums[i] == 1) {
                curr.push_back(i);
                ones = true;
            } else if (ones && nums[i] == 0) {
                curr.push_back(i);
                intervals.push_back(curr);
                ones = false;
                curr = {};
            }
        }
        if (intervals.empty()) {
            return curr.empty() ? 1 : nums.size();
        }
        
        if (!curr.empty())
            intervals.push_back(curr);
        
        vector<int> prev = intervals[0];
        int high = prev[0] == 0 && prev[1] == nums.size()-2 ? prev[1] - prev[0] : prev[1] - prev[0] + 1;

        for (int i = 1; i < intervals.size(); ++i) {
            curr = intervals[i];
            if (curr.size() == 2) {
                if (curr[0] == prev[1]+1) {
                    high = max(curr[1]-prev[0], high);
                } else {
                    high = max(curr[1]-curr[0]+1, high);
                }
            } else {
                if (curr[0] == prev[1]+1) {
                    high = max(nums.size()-prev[0], high);
                } else {
                    high = max(nums.size()-curr[0]+1, high);
                }
            }
            prev = curr;
        }
        return high;
            
    }
    
    int max(const int &a, const int &b) {
        return a < b ? b : a;
    }
};
