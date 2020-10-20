class Solution {
public:
    int numSquares(int n) {
        int limit = n > 100 ? sqrt(n) : n / 2;
        vector<int> squares;
        for (int i = 1 ; i <= limit; ++i) {
            squares.push_back(i*i);
            if (squares.back() == n) return 1;
        }
        
        int count = n;
        while (squares.size() > 1) {
            for (int i = squares.size() - 1; i > 0; --i) {
                int cand = squares.back(), curr_count = 1, head = i;
                while (head >= 0 && cand < n && curr_count < count) {
                    if (cand + squares[head] == n) {
                        count = min(curr_count + 1, count);
                        break;
                    } else if (cand + squares[head] > n) {
                        head--;
                    } else {
                        cand += squares[head];
                        curr_count++;
                    }
                }
            }
            squares.pop_back();
        }
        return count;
    }
};
};

