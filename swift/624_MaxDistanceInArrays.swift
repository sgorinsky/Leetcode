class Solution {
    func maxDistance(_ arrays: [[Int]]) -> Int {
        var low: Int = arrays[0][0], high: Int = arrays[0].last!, maxDist: Int = 0
        for i in 1..<arrays.count {
            var currArray = arrays[i]
            maxDist = findExtrema([currArray.last! - low, high - currArray[0], maxDist])
            low = findExtrema([currArray[0], low], false)
            high = findExtrema([currArray.last!, high])
        }
        return maxDist
    }
    
    func findExtrema(_ nums: [Int], _ isMax: Bool = true) -> Int {
        var high = -1000000, low = 1000000
        for n in nums {
            high = n > high ? n : high
            low = n < low ? n : low
        }
        return isMax ? high : low
    }
}
