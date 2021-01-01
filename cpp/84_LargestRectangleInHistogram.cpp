class Solution {
public:
    int biggest = 0;
    int largestRectangleArea(vector<int>& heights) {
        dc(heights, 0, heights.size() - 1);
        return biggest;
    }
    
    void dc(vector<int>& heights, int start, int end) {
        if (start > end) return;
        
        int small = heights[start];
        int small_idx = start;
        for (int i = start; i <= end; ++i) {
            if (heights[i] < small) {
                small = heights[i];
                small_idx = i;
            }
        }
        biggest = max(small * (end - start + 1), biggest);
        dc(heights, start, small_idx - 1);
        dc(heights, small_idx + 1, end);
    }
};
