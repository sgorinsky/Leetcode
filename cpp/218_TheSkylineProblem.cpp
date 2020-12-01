class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> critical_points;
        for (vector<int>& b : buildings) {
            critical_points.push_back({b[0], b[2], true});
            critical_points.push_back({b[1], b[2], false});
        }
        
        sort(critical_points.begin(), critical_points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return (a[2] ? a[1] : -a[1]) > (b[2] ? b[1] : -b[1]);
        });
        
        set<int> pq = {0};    
        vector<vector<int>> res;
        for (int i = 0; i < critical_points.size(); ++i) {
            vector<int>& point = critical_points[i];
            bool start = point[2];
            int x = point[0], y = point[1];
            int top_pq = (int) *pq.rbegin();
            cout << "x: " << x << ", y: " << y << ", start? " << start << endl;
            cout << "prior_top of pq: " << top_pq << endl;
            if (start) {
                // if (i == 0 || critical_points[i-1][1] != y) 
                pq.insert(y);
            } else {
                if (i == critical_points.size() - 1 || !(!critical_points[i+1][2] && y == critical_points[i+1][1])) {
                    pq.erase(y);
                }
            }
            cout << "new_top of pq: " << *pq.rbegin() << endl;
            if (top_pq != *pq.rbegin()) res.push_back({x, *pq.rbegin()});
        }
        return res;
    }
};

// [[2,9,10],[3,9,9],[5,12,12],[15,20,10],[19,24,8]]
// [[1,2,5], [1,3,4],[4,6,5],[5,7,5],[6,8,5],[8,9,5]]
