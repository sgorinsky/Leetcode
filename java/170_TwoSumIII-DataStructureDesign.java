class TwoSum {
    HashMap<Integer, Integer> numCounts;

    /** Initialize your data structure here. */
    public TwoSum() {
        numCounts = new HashMap<Integer, Integer>();
    }
    
    /** Add the number to an internal data structure.. */
    public void add(int number) {
        numCounts.put(number, numCounts.getOrDefault(number, 0) + 1);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public boolean find(int value) {
        for (Integer n : numCounts.keySet()) {
            if (value == 0) {
                if ((n != 0 && numCounts.get(-n) != null) || numCounts.getOrDefault(0, 0) > 1) return true;
            } else if (numCounts.get(value - n) != null) {
                if (value - n == n) return numCounts.get(n) > 1;
                return true;
            }
        }
        return false;
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */
