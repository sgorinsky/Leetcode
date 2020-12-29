class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        while (target > 0) target -= ++k;
        return target % 2 == 0 ? k : k + 1 + k % 2;
    }
};

// bfs too slow work towards above ^
class Solution {
public:
    int reachNumber(int target) {
        vector<int> positions = {0};
        int step = 1;
        while (!positions.empty()) {
            vector<int> next;
            for (int p : positions) {
                if (p == target) return step - 1;
                next.push_back(p - step);
                next.push_back(p + step);
            }
            positions = next;
            step++;
        }
        return -1;
    }
};
