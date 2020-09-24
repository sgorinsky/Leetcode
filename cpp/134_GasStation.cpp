class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0, curr_tank = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            if (curr_tank < 0) {
                start = i;
                curr_tank = 0;
            }
            int diff = gas[i] - cost[i];
            total_tank += diff;
            curr_tank += diff;
        }
        return total_tank >= 0 ? start : -1;
    }
};
