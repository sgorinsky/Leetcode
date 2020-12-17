class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sums;
        for (int a : A) {
            for (int b : B) {
                sums[a + b] = sums.find(a + b) == sums.end() ? 1 : sums[a + b] + 1;
            }
        }
        
        int count = 0;
        for (int c : C) {
            for (int d : D) {
                if (sums.find(-(c+d)) != sums.end())
                    count += sums[-(c+d)];
            }
        }
        return count;
    }
};
