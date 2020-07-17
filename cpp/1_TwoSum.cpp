class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndices;
        for (int i = 0; i < nums.size(); ++i) {
            if (numIndices.count(target-nums[i])) { 
                return {numIndices[target-nums[i]], i};
            }
            numIndices[nums[i]] = i;
        }
        
        return {-1, -1};
    }
};
