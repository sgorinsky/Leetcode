class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead_set;
        for (string deadend : deadends) dead_set.insert(deadend);
        
        queue<pair<string, int>> q; // holds current traversal + count
        q.push({"0000", 0});
        unordered_set<string> visited;
        
        while (!q.empty()) {
            pair<string, int> both = q.front();
            q.pop();
            
            string curr = both.first;
            int count = both.second;
            if (dead_set.find(curr) != dead_set.end()) continue;
            else if (curr == target) return count;
            else if (dead_set.find(curr) == dead_set.end()) {
                for (int i = 0; i < curr.length(); ++i) {
                    for (int digit = 9; digit <= 11; digit += 2) {
                        string next = curr;
                        int d = digit % 10;
                        int char_to_change = (((int) curr[i]) - ((int) '0') + d) % 10;
                        next[i] = (char) char_to_change + '0';

                        if (visited.find(next) == visited.end()) {
                            visited.insert(next);
                            q.push({next, count + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
