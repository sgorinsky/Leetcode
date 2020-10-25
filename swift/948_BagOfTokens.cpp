class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        if (tokens.empty() || P < tokens[0]) return 0;
        else if (tokens.size() == 1) return P >= tokens[0] ? 1 : 0;
        
        int left = 0, right = tokens.size() - 1, score = 0;
        while (left < right) {
            if (P >= tokens[left]) {
                while (left < tokens.size() && P >= tokens[left]) {
                    P -= tokens[left++];
                    score++;
                }
            } else if (score > 0) {
                if (left + 1 == right) break;
                P += tokens[right--];
                score--;
            }
        }
        return score;
    }
};
