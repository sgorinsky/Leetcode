class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        deque<vector<int>> q;
        q.push_front({sr, sc});
        
        int start_color = image[sr][sc];
        if (image[sr][sc] == 0) return image;
        image[sr][sc] = newColor;
        
        while (!q.empty()) {
            vector<int> curr_indices = q.front();
            q.pop_front();
            
            int i = curr_indices[0], j = curr_indices[1];
            for (vector<int> direction : directions) {
                int r = i + direction[0], c = j + direction[1];
                if (can_go(image, r, c, start_color)) {
                    image[r][c] = newColor;
                    q.push_front({r, c});
                }
            }
        }
        return image;
    }
    
    bool can_go(vector<vector<int>>& image, int i, int j, int start_color) {
        return i >= 0 && i < image.size() && j >= 0 && j < image[0].size() && image[i][j] > 0 && image[i][j] == start_color ;
    }
};
