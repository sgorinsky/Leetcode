class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        int balloon_count = 0, current_start = -123456, current_end = -123456;
        for (vector<int>& point : points) {
            if (current_start <= point[0] && current_end >= point[0]) {
                current_end = min(point[1], current_end);
            } else {
                balloon_count += 1;
                current_start = point[0];
                current_end = point[1];
            }
        }
        return balloon_count;
    }
};
