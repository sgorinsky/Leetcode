class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        unordered_set<int> distance_set;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i] == points[j]) 
                    return false;
                
                distance_set.insert(get_distance(points[i], points[j]));
            }
        }
        return distance_set.size() == 2;
    }
    
    int get_distance(const vector<int>& a, const vector<int>& b) {
        return (b[1] - a[1]) * (b[1] - a[1]) + (b[0] - a[0]) * (b[0] - a[0]);
    }
};
