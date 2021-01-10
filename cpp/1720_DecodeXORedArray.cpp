class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res = {first};
        for (int n : encoded) {
            res.push_back(res.back() ^ n);
        }
        return res;
    }
};
