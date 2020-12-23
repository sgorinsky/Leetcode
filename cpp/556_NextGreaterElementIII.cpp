class Solution {
public:
    int nextGreaterElement(int n) {
        deque<int> digits;
        while (n > 0) {
            digits.push_front(n % 10);
            n /= 10;
        }
        
        bool switched = false;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int smallest = 10, idx = 9;
            for (int j = i + 1; j < digits.size(); ++j) {
                if (digits[j] > digits[i]) {
                    if (digits[j] < smallest) {
                        smallest = digits[j];
                        idx = j;
                    }
                    switched = true;
                }
            }
            if (switched) {
                int temp = digits[idx];
                digits[idx] = digits[i];
                digits[i] = smallest;
                sort(digits.begin() + i + 1, digits.end());
                break;
            };
        }
        
        if (!switched) return -1;
        
        long int ans = 0;
        while (!digits.empty()) {
            ans *= 10;
            ans += digits.front();
            digits.pop_front();
        }
        return ans <= INT_MAX ? ans : - 1;
    }
};
