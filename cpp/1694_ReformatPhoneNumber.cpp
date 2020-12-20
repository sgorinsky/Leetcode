class Solution {
public:
    string reformatNumber(string number) {
        string num = "";
        for (char c : number) {
            if (c != ' ' && c != '-')
                num += c;
        }
        

        int l = num.length();
        string res = "";
        int idx = 0;
        while (l > 4 && idx < l) {
            res += num[idx];
            if (++idx % 3 == 0) {
                if (idx != l - 1) res += '-';
                if (l - idx <= 4) break;
            }
        }
        
        int r = l - idx;
        int j = 0;
        for (int i = idx; i < l; ++i) {
            if (r % 3 == 0 || r == 2) {
                res += num[i];
            } else {
                res += num[i];
                j++;
                if (j % 2 == 0 && i != l - 1)
                    res += '-';
            }
        }
        return res;
    }
};
