class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int left = 0, right = 0, highest = 0;
        
        while (right < seats.size() && seats[right] != 1) {
            right++;
            highest++;
        }
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 1) {
                right = i + 1, left = i;
                while (right < seats.size() && seats[right] == 0) right++;
                if (right == seats.size()) return max(right - 1 - i, highest);
            } else {
                highest = max(min(right - i, i - left),  highest);
            }
        }
        return highest;
    }
};

