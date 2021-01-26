class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int N = matrix.size(), M = matrix[0].size();
        priority_queue<int> xors;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[i][j] ^= (i > 0 ? matrix[i-1][j] : 0) ^ (j > 0 ? matrix[i][j-1] : 0);
                xors.push(matrix[i][j]);
                if (i < N - 1 && j < M - 1)
                    matrix[i + 1][j + 1] ^= matrix[i][j];
            }
        }
        
        while (--k > 0)
            xors.pop();
        
        return xors.top();
    }
};
