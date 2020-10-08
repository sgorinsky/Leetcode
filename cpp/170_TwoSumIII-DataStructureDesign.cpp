class TwoSum {
public:
    unordered_map<int, int> numbers_seen;
    vector<int> numbers;
    /** Initialize your data structure here. */
    TwoSum() {}
    
    /** Add the number to an internal data structure.. */
    void add(int n) {
        numbers_seen[n] = numbers_seen.count(n) > 0 ? numbers_seen[n] + 1 : 1;
        numbers.push_back(n);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        
        for (int n : numbers) {
            if (value != 0) {
                if (numbers_seen.count(value - n) > 0) {
                    if (value - n == n && value != 0)  return numbers_seen[n] > 1;
                    return true;
                }
            } else {
                if (n == 0) {
                    if (numbers_seen[n] > 1) return true;
                } else if (numbers_seen.count(value - n) > 0) return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
