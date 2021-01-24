class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for (int j = 0; j < mat[0].size(); ++j)
            diagonal_sort(mat, 0, j);
        
        for (int i = 0; i < mat.size(); ++i)
            diagonal_sort(mat, i, 0);
        
        return mat;
    }
    
    void diagonal_sort(vector<vector<int>>& m, int row, int col) {
        vector<int> entries;
        int i = row, j = col;
        while (i < m.size() && j < m[0].size())
            entries.push_back(m[i++][j++]);
        
        sort(entries.begin(), entries.end());
        i = row, j = col;
        for (int e : entries)
            m[i++][j++] = e;
    }
};
