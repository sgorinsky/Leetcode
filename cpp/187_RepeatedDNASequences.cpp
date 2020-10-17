class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int L = 10, n = s.length();
        if (n <= L) 
            return {};
        
        // hash params
        int a = 4, aL = pow(a, L);
        
        unordered_map<char, int> nucleotides = {
            { 'A', 0 },
            { 'C', 1 },
            { 'G', 2 },
            { 'T', 3 }
        };
        vector<int> nums;
        for (int i = 0; i < n; ++i) nums.push_back(nucleotides[s[i]]);
        
        int h = 0;
        unordered_set<int> seen;
        unordered_set<string> output;
        
        for (int start = 0; start < n - L + 1; ++start) {
            if (start > 0) h = h * a - nums[start - 1] * aL + nums[start + L - 1];
            else for (int i = 0; i < L; ++i) h = h * a + nums[i];
            
            if (seen.find(h) != seen.end()) output.insert(s.substr(start, L));
            seen.insert(h);
        }
        
        vector<string> result;
        for (string slice : output)
            result.push_back(slice);
        
        return result;
            
        
    }
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 11) return {};
        unordered_map<string, int> string_counts;
        for (int i = 0; i <= s.length() - 10; ++i) {
            string curr_substr = s.substr(i, 10);
            if (string_counts.find(curr_substr) == string_counts.end()) string_counts[curr_substr] = 1;
            else string_counts[curr_substr]++;
        }
        
        vector<string> result;
        for (auto entry : string_counts) {
            if (entry.second > 1) result.push_back(entry.first);
        }
        return result;
    }
};
