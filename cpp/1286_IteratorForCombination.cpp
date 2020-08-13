class CombinationIterator {
public:
    deque<string> combinations = {};
    CombinationIterator(string characters, int combinationLength) {
        int n = characters.length(), k = combinationLength;
        
        for (int bitmask = 0; bitmask < 1 << n; ++bitmask) {
            if (countBits(bitmask) == k) {
                string curr = "";
                for (int j = 0; j < n; ++j) {
                    if ((bitmask & (1 << n - j - 1)) != 0) 
                        curr += characters[j];
                }
                combinations.push_back(curr);
            }
        }
    }
    
    string next() {
        string end = combinations.back();
        combinations.pop_back();
        return end;
    }
    
    bool hasNext() {
        return !combinations.empty();
    }
    
    int countBits(int n) {
        int count = 0;
        while (n > 0) {
            ++count;
            n &= n-1;
        }
        return count;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
