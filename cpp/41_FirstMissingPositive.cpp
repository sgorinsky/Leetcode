class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (int n : nums)
            if (n > 0)
                num_set.insert(n);
        
        int i = 0;
        while (i++ < INT_MAX) {
            if (num_set.find(i) == num_set.end())
                return i;
        }
        return -1;
    }
};
