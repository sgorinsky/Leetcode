class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> num_set;
        int N = nums.size();
        int small = N, big = 0;
        // populate set
        for (int n : nums)
            num_set.insert(n);
        
        vector<int> missing;
        for (int i = 1; i <= N ; ++i) {
            if (num_set.find(i) == num_set.end())
                missing.push_back(i);
        }
        return missing;
    }
};
