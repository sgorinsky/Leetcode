class MovingAverage {
public:
    deque<int> queue = {};
    int size;
    double total = 0;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        if (queue.size() == size) {
            total -= queue[0];
            queue.pop_front();
        }
        queue.push_back(val);
        total += val;
        return total / queue.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
