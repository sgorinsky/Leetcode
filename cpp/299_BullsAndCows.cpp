class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> secret_counts;
        for (char c : secret)
            secret_counts[c] = secret_counts.find(c) == secret_counts.end() ? 1 : secret_counts[c] + 1;
        
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.length(); ++i) {
            char c = secret[i];
            if (c == guess[i]) {
                ++bulls;
                --secret_counts[c];
            }
        }
        for (int i = 0; i < guess.length(); ++i) {
            char c = guess[i];
            if (secret_counts.find(c) != secret_counts.end() && 
                secret_counts[c] > 0 &&
                c != secret[i]) {
                ++cows;
                --secret_counts[c];
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
