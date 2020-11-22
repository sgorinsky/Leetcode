class Solution {
public:
    vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> uniques;
        for (string word : words) {
            string curr = "";
            for (char c : word) {
                curr += codes[c - 'a'];
            }
            uniques.insert(curr);
        }
        return uniques.size();
    }
};
