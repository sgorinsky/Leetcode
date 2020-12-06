class Solution {
public:
    unordered_map<string, string> map = {{"()", "o"}, {"(al)", "al"}};
    string interpret(string command) {
        deque<char> q;
        string curr = "";
        string res = "";
        for (char c : command) {
            if (c == ')') {
                while (!q.empty()) {
                    curr += q.front();
                    q.pop_front();
                }
                curr += ")";
                res += map[curr];
                curr = "";
            } else if (c == 'G') {
                res += c;
            } else {
                q.push_back(c);
            }
        }
        return res;
    }
};
