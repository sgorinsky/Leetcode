class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res = {};
        if (nums.size() == 0) {
            res.push_back(lower != upper ? to_string(lower)+"->"+to_string(upper) : to_string(lower));
            return res;
        }
        
        if (nums[0] > lower) {
            res.push_back(nums[0]-1 == lower ? to_string(lower) : to_string(lower) + "->" + to_string(nums[0]-1));
        }
                                                                                                                     
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1] && nums[i]-1 != nums[i-1]) {
                if (nums[i]-1 == nums[i-1]+1) {
                    res.push_back(to_string(nums[i]-1));
                } else {
                    res.push_back(to_string(nums[i-1]+1) + "->" + to_string(nums[i]-1));
                }
            }
            if (nums[i] > upper) break;
        }
        
        int last = nums.size()-1;
        if (nums[last] < upper) {
            res.push_back(nums[last]+1 == upper ? to_string(upper) : to_string(nums[last]+1) + "->" + to_string(upper));
        }
        return res;
    }
};
