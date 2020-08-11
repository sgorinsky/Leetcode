class Solution {
    func combinationSum(_ candidates: [Int], _ target: Int) -> [[Int]] {
        var results = [[Int]]() 
        
        func helper(_ curr: inout [Int], _ idx: Int, _ sum: Int) -> [[Int]] {
            if sum == target {
                results.append(curr)
                return results
            } else if sum > target {
                return results
            }
            
            for i in idx..<candidates.count {
                let cand = candidates[i]
                curr.append(cand)
                helper(&curr, i, sum+cand)
                curr.removeLast()
            }
            return results
        }
        
        var curr = [Int]()
        return helper(&curr, 0, 0)
    }
}
