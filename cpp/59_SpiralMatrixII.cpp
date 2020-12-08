class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int left = 0, right = n - 1, up = 1, down = n - 1;
        int i = 0, j = 0;
        int direction = 0; // 0 - right, 1 - down, 2 - left, 3 - up
        for (int x = 1; x <= n * n; ++x) {
            matrix[i][j] = x;
            if (direction == 0) {
                if (j == right) {
                    right--;
                    direction = (direction + 1) % 4;
                    i++;
                } else {
                    j++;
                }
            } else if (direction == 1) {
                if (i == down) {
                    down--;
                    direction = (direction + 1) % 4;
                    j--;
                } else {
                    i++;
                }
            } else if (direction == 2) {
                if (j == left) {
                    left++;
                    direction = (direction + 1) % 4;
                    i--;
                } else {
                    j--;
                }
            } else {
                if (i == up) {
                    up++;
                    direction = (direction + 1) % 4;
                    j++;
                } else {
                    i--;
                }
            }
        }
        return matrix;
    }
};
