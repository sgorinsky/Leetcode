class OrderedStream {
public:
    int idx = 1;
    vector<string> strings;
    OrderedStream(int n) {
        for (int i = 1; i < 1001; ++i) strings.push_back("");
    }
    
    vector<string> insert(int id, string value) {
        strings[id] = value;
        vector<string> res;
        int i = idx;
        while (strings[i] != "") {
            res.push_back(strings[i++]);
        }
        idx = i;
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
