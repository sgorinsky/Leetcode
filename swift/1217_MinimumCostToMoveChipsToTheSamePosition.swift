class Solution {
    func minCostToMoveChips(_ positions: [Int]) -> Int {
        var evens = 0, odds = 0
        for p in positions {
            if p % 2 == 0 { evens += 1 }
            else { odds += 1 }
        }
        return min(odds, evens)
    }
}
