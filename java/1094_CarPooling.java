class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] buckets = new int[1001];
        for (int[] trip : trips){
            buckets[trip[1]] += trip[0]; // beginning of carrying passengers
            buckets[trip[2]] -= trip[0]; // end of carrying passengers
        }
        
        int totalCurrentCapacity = 0;
        for (int numPeople : buckets) {
            totalCurrentCapacity += numPeople;
            if (totalCurrentCapacity > capacity)
                return false;
        }
        return true;
    }
}
