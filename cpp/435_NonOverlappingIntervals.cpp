class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) 
            return 0;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
        });
        
        vector<int> curr = intervals[0];
        int count = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> interval = intervals[i];
            if (curr[1] > interval[0]) {
                curr = interval[1] < curr[1] ? interval : curr;
                count += 1;
            } else {
                curr = interval;
            }
        }
        return count;
    }
};
