class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiralElements;
        int i = 0, j = 0, layer = 0;
        int m =  matrix.size(), n = matrix[0].size();
        int rowSz = m - 1, colSz = n - 1;
        for (int x = 0; x < m * n; ++x) {
            if (matrix[i][j] == 101) {
                layer++, colSz--, rowSz--;
                i = j = layer;
            }
            
            spiralElements.push_back(matrix[i][j]);
            matrix[i][j] = 101;
            
            if (j < colSz && i == layer) j++;
            else if (i < rowSz && j == colSz) i++;
            else if (j > layer && i == rowSz) j--;
            else i--;
        }
        return spiralElements;
    }
};
