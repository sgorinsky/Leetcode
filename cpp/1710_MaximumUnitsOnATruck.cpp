class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        int total = 0; 
        int i = 0;
        while (i < boxTypes.size() && truckSize > 0) {
            vector<int> box = boxTypes[i];
            if (truckSize < box[0]) {
                total += (truckSize * box[1]);
                truckSize = 0;
            } else {
                truckSize -= box[0];
                total += (box[0] * box[1]);
            }
            i++;
        }
        return total;
    }
};
