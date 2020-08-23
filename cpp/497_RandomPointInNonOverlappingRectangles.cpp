class Solution {
public:
    vector<vector<int>> rects;
    vector<int> areas;
    int total_area = 0;
    
    int area(vector<int>& r) {
        return (r[3] - r[1] + 1) * (r[2] - r[0] + 1);
    }
    
    Solution(vector<vector<int>>& rs) {
        rects = rs;
        for (vector<int> r : rects) {
            int a = area(r);
            total_area += a;
            areas.push_back(total_area);
        }
    }
    
    vector<int> pick() {
        int rand_area = rand() % areas.back();
        int idx = upper_bound(areas.begin(), areas.end(), rand_area) - areas.begin();
        
        vector<int> r = rects[idx];
        int x = rand() % (r[2] - r[0] + 1) + r[0];
        int y = rand() % (r[3] - r[1] + 1) + r[1];
        return { x, y };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
