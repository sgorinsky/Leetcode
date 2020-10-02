class RecentCounter {
public:
    deque<int> request_stack;
    int high_range;
    RecentCounter() {
        request_stack = {};
        high_range = 0;
    }
    
    int ping(int t) {
        high_range = t; // strictly increasing values of t
        while (!request_stack.empty() && high_range - 3000 > request_stack.front())
            request_stack.pop_front();
        request_stack.push_back(t);
        return request_stack.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
