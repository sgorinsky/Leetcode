class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newIntervals;
        int size = intervals.size();
        if (size == 0) {
            intervals.push_back(newInterval);
            return intervals;
        } else if (newInterval[1] < intervals[0][0]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        } else if (newInterval[0] > intervals[size-1][1]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        vector<int> curr = newInterval;
        
        for (int i = 0; i < size; ++i) {
            vector<int> interval = intervals[i];
            if (overlaps(curr, interval)) {
                while (i < size && overlaps(curr, intervals[i])) {
                    interval = intervals[i++];
                    curr = {min(curr[0], interval[0]), max(curr[1], interval[1])};
                }
                newIntervals.push_back(curr);
                if (i < size && !overlaps(curr, intervals[i]))
                    newIntervals.push_back(intervals[i]);
                
                continue;
            } else if (i > 0 && in_between(curr, intervals[i-1], interval)) {
                newIntervals.push_back(curr);
            }
            newIntervals.push_back(interval);
        }
        return newIntervals;
    }
    
    bool overlaps(vector<int>& a, vector<int>& b) {
        return (a[1] >= b[0] && a[1] <= b[1]) || (a[0] >= b[0] && a[0] <= b[1]) || (a[0] <= b[0] && a[1] >= b[1]);
    }  
    
    bool in_between(vector<int>& candidate, vector<int>& a, vector<int>& b) {
        return candidate[0] > a[1] && candidate[1] < b[0];
    }
};
