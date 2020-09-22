class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> buckets(1001, 0);
        for (vector<int> trip : trips) {
            buckets[trip[1]] += trip[0];
            buckets[trip[2]] -= trip[0];
        }
        int curr_capacity = 0;
        for (int n : buckets) {
            curr_capacity += n;
            if (curr_capacity > capacity)
                return false;
        }
        return true;
    }
};
