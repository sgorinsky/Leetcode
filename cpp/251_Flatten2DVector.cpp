class Vector2D {
public:
    int head;
    vector<int> vect;
    Vector2D(vector<vector<int>>& v) {
        for (vector<int>& nums : v) {
            for (int num : nums) {
                vect.push_back(num);
            }
        }
        head = 0;
    }
    
    int next() {
        return vect[head++];
    }
    
    bool hasNext() {
        return head < vect.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
