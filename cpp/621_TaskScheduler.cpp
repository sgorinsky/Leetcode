class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> num_counts;
        int high = 0;
        for (char t : tasks) {
            num_counts[t] = num_counts.find(t) == num_counts.end() ? 1 : num_counts[t] + 1;
            if (num_counts[t] > high) high = num_counts[t];
        }
        
        int n_max = 0;
        for (auto entry : num_counts) {
            if (entry.second == high) {
                ++n_max;
            }
        }
        return (high-1) * (n+1) + n_max < tasks.size() ? tasks.size() : (high-1) * (n+1) + n_max;
    }
};
