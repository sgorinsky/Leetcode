class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        if (high <= low) 
            return result;
        
        int divisor = 10, add = 1;
        int begin = 1;
        while (low / divisor > 0) {
            divisor *= 10;
            begin = (begin * 10) + (begin % 10 + 1);
            add = (add * 10) + 1;
        }
        
        int start = begin;
        while (start <= high) {
            if (start >= low)
                result.push_back(start);

            start += add;
            if (start % 10 == 0) {
                begin = (begin * 10) + (begin % 10 + 1);
                start = begin;
                add = add * 10 + 1;
            }
        }
        return result;
    }
};
