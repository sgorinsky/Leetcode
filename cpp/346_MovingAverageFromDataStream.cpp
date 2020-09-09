class MovingAverage {
public:
    deque<int> nums;
    int size;
    double total;
    /** Initialize your data structure here. */
    MovingAverage(int sz) {
        size = sz;
        total = 0;
    }
    
    double next(int val) {
        if (nums.size() == size) {
            total -= nums.front();
            nums.pop_front();
        }
        total += val;
        nums.push_back(val);
        return total / nums.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

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
