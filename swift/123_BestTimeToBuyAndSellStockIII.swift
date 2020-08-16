class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        var t1Cost: Int = Int.max, t1Profit: Int = 0
        var t2Cost: Int = Int.max, t2Profit: Int = 0
        
        for price in prices {
            t1Cost = min(price, t1Cost)
            t1Profit = max(t1Profit, price - t1Cost)
            
            t2Cost = min(t2Cost, price - t1Profit)
            t2Profit = max(t2Profit, price - t2Cost)
        }
        return t2Profit
    }
}
