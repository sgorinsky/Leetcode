class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int total = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<int> potential_coverer = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (potential_coverer[0] <= intervals[i][0] && potential_coverer[1] >= intervals[i][1]) {
                total--;
            } else {
                potential_coverer = intervals[i];
            }
        }
        return total;
    }
};
