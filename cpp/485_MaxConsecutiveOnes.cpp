class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0, currOnes = 0;
        for (int n : nums) {
            if (n == 1) {
                ++currOnes;
                if (currOnes > maxOnes) maxOnes = currOnes;
            } else {
                currOnes = 0;
            }
        }
        return maxOnes;
    }
};
