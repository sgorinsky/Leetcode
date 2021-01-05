class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        var profit = 0
        var small = Int.max
        for p in prices {
            if p < small {
                small = p
            } else {
                profit = max(p - small, profit)
            }
        }
        return profit
    }
}
