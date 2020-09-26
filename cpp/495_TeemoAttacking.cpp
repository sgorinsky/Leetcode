class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        
        int total_time = 0, end = 0;
        for (int t : timeSeries) {
            total_time += min(t + duration - end, duration);
            end = t + duration;
        }
        return total_time;
    }
};
