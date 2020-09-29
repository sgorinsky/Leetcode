class Solution {
    func combinationSum4(_ nums: [Int], _ target: Int) -> Int {
        var cache: [Int : Int] = [Int : Int]()
        
        func countCombinations(_ sum: Int) -> Int {
            if sum == target {
                return 1
            } else if sum > target {
                return 0
            } else if let cacheSum = cache[sum]{
                return cacheSum
            }
            
            var total: Int = 0
            for (i, n) in nums.enumerated() {
                var potentialSum: Int = sum + n
                if cache[potentialSum] == nil {
                    cache[potentialSum] = countCombinations(potentialSum)
                }
                total += cache[potentialSum]!
            }
            return total
        }
        return countCombinations(0)
    }
}
