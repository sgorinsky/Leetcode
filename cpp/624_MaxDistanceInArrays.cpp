class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int high = arrays[0].back(), low = arrays[0][0], max_dist = 0;
        for (int i = 1; i < arrays.size(); ++i) {
            vector<int> curr_array = arrays[i];
            max_dist = max(max(high - curr_array[0], curr_array.back() - low), max_dist);
            low = min(curr_array[0], low);
            high = max(curr_array.back(), high);
        }
        return max_dist;
    }
};
