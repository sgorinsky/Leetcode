class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> unsorted_heights;
        copy(heights.begin(), heights.end(), back_inserter(unsorted_heights));
        
        sort(heights.begin(), heights.end(), [](const int& a, const int& b) {
            return a < b;
        });
        
        int count = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != unsorted_heights[i])
                ++count;
        }
        return count;
    }
};
