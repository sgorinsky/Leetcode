class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int N = intervals.size(), max_start = 0;
        unordered_map<int, int> start_points;
        
        for (int i = 0; i < N; ++i) {
            int start = intervals[i][0];
            if (start_points.find(start) == start_points.end()) {
                start_points[start] = i;
                max_start = max(max_start, start);
            }
        }
        
        vector<int> rights(N, -1);
        for (int i = 0; i < N; ++i) {
            vector<int> curr = intervals[i];
            if (max_start >= curr[1]) {
                for (int j = curr[1]; j <= max_start; ++j) {
                    if (start_points.find(j) != start_points.end() && start_points[j] != i) {
                        rights[i] = start_points[j];
                        break;
                    } else if (curr[0] == curr[1]) {
                        rights[i] = i;
                        break;
                    }
                }
            }
        }
        return rights;
    }
};
