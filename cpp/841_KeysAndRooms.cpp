class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.empty()) return false;
        
        vector<vector<int>> stack;
        stack.push_back(rooms[0]);
        unordered_set<int> rooms_not_visited;
        
        for (int i = 1; i < rooms.size(); ++i) 
            rooms_not_visited.insert(i);
        
        while (!stack.empty()) {
            vector<int> keys = stack.back();
            stack.pop_back();
            for (int key : keys) {
                if (rooms_not_visited.find(key) != rooms_not_visited.end()) {
                    stack.push_back(rooms[key]);
                    rooms_not_visited.erase(key);
                }
            }
            if (rooms_not_visited.empty()) return true;
        }
        return false;
    }
};
