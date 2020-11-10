class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (vector<int>& row : A) {
            int left = 0, right = row.size() - 1;
            while (left <= right) {
                int temp = !row[left];
                row[left++] = !row[right];
                row[right--] = temp;
            }
        }
        return A;
    }
};
