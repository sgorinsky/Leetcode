class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> crit_points;
        unordered_map<int, int> starts, ends;
        for (const vector<int>& building : buildings) {
            crit_points.push_back({building[0], building[2], true});
            starts[building[0]] = building[2];
            
            crit_points.push_back({building[1], building[2], false});
            ends[building[1]] = building[2];
        }
        
        sort(crit_points.begin(), crit_points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return (a[2] ? a[1] : -a[1]) > (b[2] ? b[1] : -b[1]);
        });
        
        vector<vector<int>> ans;
        set<int> pq = {0};
        unordered_map<int, int> height_counts; // covers corner cases
        for (int i = 0; i < crit_points.size(); ++i) {
            const vector<int>& point = crit_points[i];
            int top_pq = *pq.rbegin();
            int x = point[0], h = point[1];
            bool start = point[2];
            if (start) {
                pq.insert(h);
                if (height_counts.find(h) == height_counts.end()) height_counts[h] = 1;
                else height_counts[h] += 1;
            } else {
                height_counts[h] -= 1;
                if (height_counts[h] == 0 && (starts.find(x) == starts.end() || starts[x] != h)) pq.erase(h);
            }
            if (top_pq != *pq.rbegin()) ans.push_back({x, *pq.rbegin()});
        }
        return ans;
    }
};
