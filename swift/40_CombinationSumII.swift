class Solution {
    func combinationSum2(_ cands: [Int], _ target: Int) -> [[Int]] {
        var result: [[Int]] = [[Int]]()
        var candidates = cands.sorted(by: {
            a, b in 
            return a < b
        })

        func combine(_ curr: [Int], _ sum: Int, _ idx: Int = 0) {
            var size: Int = curr.count
            if sum == target {
                result.append(curr)
                return
            } else if sum > target {
                return
            } 
            
            for i in idx..<candidates.count {
                var n: Int = candidates[i]
                
                // to ensure we consider duplicates once, cands[i] != cands[i-1] if i has moved beyond its original starting point idx in the recursion stack's loop
                if size > 0 && n < curr[size-1] || i != idx && candidates[i] == candidates[i-1] { continue }
                combine(curr + [n], sum + n, i + 1)
            }
        }
        combine([], 0, 0)
        return result
    }
}
