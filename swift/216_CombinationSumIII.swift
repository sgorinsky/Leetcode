class Solution {
    func combinationSum3(_ k: Int, _ n: Int) -> [[Int]] {
        var result: [[Int]] = [[Int]]()
        var top = n < 9 ? n : 9
        
        func combine(_ curr: [Int], _ sum: Int) {
            var size: Int = curr.count
            if k == size && sum == n {
                result.append(curr)
                return
            } else if size >= k || sum >= n {
                return
            }
            
            var start = size > 0 ? curr[size-1] + 1 : 1
            if start <= top {
                for num in start...top {
                    combine(curr + [num], sum + num)
                }
            }
        }
        combine([], 0)
        return result
    }
}
