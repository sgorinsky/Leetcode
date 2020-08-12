class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
            return {1};
        vector<int> v = getRow(rowIndex-1);
        int n = v.size();
        for(int i = 1 ; i < n ; ++i) {
            v[i] = i <= n/2 ? v[i]+v[n-i] : v[n-i];
        }
        v.push_back(1);
        return v;
    }
};

class Solution {
public:
    unordered_map<int, vector<int>> triangle;
    vector<int> getRow(int rowIndex) {
        vector<int> res = {};
        triangle[0] = vector<int>(1, 1);
        for (int col = 0; col <= rowIndex; ++col) {
            int entry = helper(rowIndex, col);
            res.push_back(entry);
        }
        return res;
    }
    
    int helper(int i, int j) {
        bool not_end = triangle.find(i) != triangle.end();
        if (not_end && triangle[i][j] != 0) {
            return triangle[i][j];
        } else if (not_end && triangle[i][i-j] != 0) {
            return triangle[i][i-j];
        } else {
            triangle[i] = vector<int>(i+1, 0);
            if (i == j || j == 0)  {
                triangle[i][j] = 1;
                return triangle[i][j];
            }
            triangle[i][j] = helper(i-1, j-1) + helper(i-1, j);
            return triangle[i][j];
        }
    }
};
