class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        
        int total = duration;
        for (int i = 1; i < timeSeries.size(); ++i)
            total += min(timeSeries[i] - timeSeries[i-1], duration);
        return total;
    }
};

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total_time = 0, end = 0;
        for (int t : timeSeries) {
            total_time += min(t + duration - end, duration);
            end = t + duration;
        }
        return total_time;
    }
};
