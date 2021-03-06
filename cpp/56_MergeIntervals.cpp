class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
            
        vector<vector<int>> merged_intervals;
        vector<int> curr = {intervals[0][0], intervals[0][1]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (curr[1] >= intervals[i][0]) {
                curr[1] = max(curr[1], intervals[i][1]);
            } else {
                merged_intervals.push_back(curr);
                curr = intervals[i];
            }
        }
        merged_intervals.push_back(curr);
        return merged_intervals;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        vector<vector<int>> res;
        vector<int> curr_range;
        bool hasStarted = false;
        
        // lambda comparator function to compare each start of interval
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        for (vector<int> range : intervals) {
            int start = range[0], end = range[1];
            if (!hasStarted) {
                curr_range = {start, end};
                hasStarted = true;
            } else if (curr_range[1] >= start) {
                curr_range[1] = curr_range[1] >= end ? curr_range[1] : end;
            } else {
                res.push_back(curr_range);
                curr_range = {start, end};
            }
        }
        res.push_back(curr_range);
        return res;
    }
};
