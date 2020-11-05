class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evens = 0, odds = 0;
        for (int ith_pos : position) {
            if (ith_pos % 2 == 0) evens++;
            else odds++;
        }
        return min(evens, odds);
    }
};
