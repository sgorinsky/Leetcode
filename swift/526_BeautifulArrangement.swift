class Solution {
    func countArrangement(_ n: Int) -> Int {
        func backtrack(_ idx: Int) -> Int {
            if idx > n {
                count += 1
                return count
            }
            
            for i in 1...n {
                if !visited[i] && (i % idx == 0 || idx % i == 0) {
                    visited[i] = true
                    backtrack(idx + 1)
                    visited[i] = false
                }
            }
            return count
        }
        var count = 0
        var visited = [Bool](repeating: false, count: n + 1)
        return backtrack(1)
    }
}
