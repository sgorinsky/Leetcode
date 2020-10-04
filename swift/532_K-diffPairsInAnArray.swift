class Solution {
    func findPairs(_ nums: [Int], _ k: Int) -> Int {
        var rollingNumCounts: [Int : Int] = [Int : Int]()
        var count: Int = 0
        for n in nums {
            var nCount = rollingNumCounts[n] ?? 0
            if k != 0 {
                if nCount == 0 { // first time seeing n so counting unique pairs
                    if rollingNumCounts[n - k] ?? 0 > 0 { count += 1 }
                    if rollingNumCounts[n + k] ?? 0 > 0 { count += 1 }
                }
            } else if nCount == 1 {
                count += 1
            }
            rollingNumCounts[n] = nCount > 0 ? nCount + 1 : 1
        }
        return count
    }
}
