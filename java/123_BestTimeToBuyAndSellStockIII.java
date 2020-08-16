class Solution {
    public int maxProfit(int[] prices) {
        int t1Cost = Integer.MAX_VALUE;
        int t1Profit = 0;
        int t2Cost = Integer.MAX_VALUE;
        int t2Profit = 0;
        
        for (int p : prices){
            t1Cost = Math.min(t1Cost, p);
            t1Profit = Math.max(t1Profit, p - t1Cost);
            
            t2Cost = Math.min(t2Cost, p - t1Profit);
            t2Profit = Math.max(t2Profit, p - t2Cost);
        }
        return t2Profit;
            
    }
}
