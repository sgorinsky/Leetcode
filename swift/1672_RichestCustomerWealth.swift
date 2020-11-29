class Solution {
    func maximumWealth(_ accounts: [[Int]]) -> Int {
        var highestSum = 0
        for account in accounts {
            var currSum = 0
            for n in account {
                currSum += n
            }
            highestSum = max(currSum, highestSum)
        }
        return highestSum
    }
}
