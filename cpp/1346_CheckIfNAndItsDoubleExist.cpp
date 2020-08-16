class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> num_set = {};
        int zeroes = 0;
        for (int n : arr) {
            if (num_set.find(n) == num_set.end())
                num_set.insert(n);
            if (n == 0) 
                ++zeroes;
        }
        
        if (zeroes > 1) 
            return true;
        
        for (int n : arr) {
            if (n != 0 && num_set.find(n*2) != num_set.end())
                return true;
        }
        return false;
    }
};
