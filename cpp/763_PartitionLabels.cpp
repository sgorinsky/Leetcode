class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_places = {};
        for (int i = 0 ; i < s.length(); ++i)
            last_places[s[i]] = i;
        
        vector<int> partitions;
        int curr = last_places[s[0]], last = 0;
        for (int i = 0; i < s.length(); ++i) {
            // cout << "i: " << i << ", letter: " << s[i] << ", last_idx: " << last_places[s[i]] << endl;
            curr = max(last_places[s[i]], curr);
            if (i == curr) {
                partitions.push_back(curr - last + 1);
                last = curr + 1;
                curr = last_places[s[i]];
            }
        }
        return partitions;
    }
};
