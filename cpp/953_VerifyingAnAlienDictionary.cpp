class Solution {
public:
    unordered_map<char, int> order_dict;
    bool isAlienSorted(vector<string>& words, string order) {
        order_dict = {};
        for (int i = 0; i < order.length(); ++i) order_dict[order[i]] = i;
        
        string prev = words[0];
        for (int i = 1; i < words.size(); ++i) {
            if (!check(prev, words[i])) return false;
            prev = words[i];
        }
        return true;
    }
    
    bool check(string w1, string w2) {
        if (w1.empty() || w2.empty()) {
            return w1.length() <= w2.length();
        } else if (order_dict[w1[0]] < order_dict[w2[0]]) {
            return true;
        } else if (order_dict[w1[0]] > order_dict[w2[0]]) {
            return false;
        } else {
            return check(w1.substr(1, w1.length()), w2.substr(1, w2.length()));
        }
    }
};
