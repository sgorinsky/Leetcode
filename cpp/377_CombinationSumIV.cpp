class Solution {
public:
    unordered_map<int, int> cache;
    int combinationSum4(vector<int>& nums, int target) {
        return combine(0, nums, target);
    }
    
    int combine(int curr_sum, vector<int>& nums, int target) {
        if (curr_sum == target)
            return 1;
        else if (curr_sum > target)
            return 0;
        else if (cache.find(curr_sum) != cache.end())
            return cache[curr_sum];
            
        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int add_element = curr_sum + nums[i];
            if (cache.find(add_element) == cache.end())
                cache[add_element] = combine(add_element, nums, target);
            total += cache[add_element];
        }
        return total;
    }
};
