class Solution {
public:
    unordered_map<int, int> smaller_counts;
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> bigger;
        vector<int> smaller_list;
        if (nums1.size() > nums2.size()) {
            bigger = nums1, smaller_list = nums2;
        } else {
            bigger = nums2, smaller_list = nums1;
        }
        
        for (int n : smaller_list) {
            smaller_counts[n] = smaller_counts.find(n) != smaller_counts.end() ? smaller_counts[n]+1 : 1;
        }
        
        vector<int> res = {};
        for (int n : bigger) {
            if (smaller_counts.find(n) != smaller_counts.end() && smaller_counts[n] != 0) {
                res.push_back(n);
                --smaller_counts[n];
            }
        }
        return res;
    }
};
