class MovingAverage {
    Queue<Integer> q;
    private double total;
    private static int capacity;
    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        q = new LinkedList<Integer>();
        total = 0;
        capacity = size;
    }
    
    public double next(int val) {
        if (q.size() == capacity) total -= q.poll();
        q.offer(val);
        total += val;
        return total / q.size();
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
