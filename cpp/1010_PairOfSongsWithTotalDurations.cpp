class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> time_mods(60, 0);
        int count = 0;
        for (int t : time) t %= 60, time_mods[t] += 1;
        for (int t = 0; t <= 30; ++t) {
            int complement = (60 - t) % 60;
            if (t == 0 || t == 30) {
                for (int x = 2; x <= time_mods[t]; ++x) 
                    count += (x - 1);
            } else 
                count += (time_mods[t] * time_mods[complement]);
        }
        return count;
    }
};
