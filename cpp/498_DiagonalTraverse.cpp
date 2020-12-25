class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int r = matrix.size(), c = matrix[0].size();
        int i = 0, j = 0;
        vector<int> diagonals;
        bool up = true;
        for (int _ = 0; _ < r * c; ++_) {
            diagonals.push_back(matrix[i][j]);
            if (up) {
                if (i == 0 || j == c - 1) {
                    if (j == c-1) i++;
                    else j++;
                    up = false;
                } else {
                    i--, j++;
                }
            } else {
                if (j == 0 || i == r - 1) {
                    if (i == r - 1) j++;
                    else i++;
                    up = true;
                } else {
                    i++, j--;
                }
            }
        }
        return diagonals;
    }
};
