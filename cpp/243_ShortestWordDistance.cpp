class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int idx = 1000000, jdx = -1000000;
        int min_dist = abs(jdx - idx);
        for (int i = 0; i < words.size(); ++i) {
            string curr = words[i];
            if (curr == word1) idx = i;
            else if (curr == word2) jdx = i;
            min_dist = min(min_dist, abs(jdx - idx));
        }
        return min_dist;
    }
};
