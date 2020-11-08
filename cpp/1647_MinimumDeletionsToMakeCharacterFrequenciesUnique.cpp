class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> char_counts;
        for (char c : s) {
            if (char_counts.find(c) != char_counts.end()){
                char_counts[c]++;
            } else {
                char_counts[c] = 1;
            }
        }
        
        unordered_map<int, char> counts;
        vector<int> counts_arr;
        for (auto entry : char_counts) {
            if (counts.find(entry.second) != counts.end()) {
                counts[entry.second]++;
            } else {
                counts[entry.second] = 1;
            }
            counts_arr.push_back(entry.second);
        }
        
        int total = 0;
        for (int i = 0; i < counts_arr.size(); ++i) {
            if (counts[counts_arr[i]] > 1) {
                while (counts[counts_arr[i]] > 1 && counts_arr[i] != 0) {
                    total++;
                    counts[counts_arr[i]]--;
                    counts_arr[i] -= 1;
                    counts[counts_arr[i]]++;
                }
            }
        }
        return total;
        
    }
};
