class Solution {
    func combine(_ n: Int, _ k: Int) -> [[Int]] {
        func helper(_ start: Int, _ currentCombination: [Int]) {
            if currentCombination.count == k {
                combinations.append(currentCombination)
            } else if start <= n {
                for i in start...n {
                    helper(i + 1, currentCombination + [i])
                }
            }
        }
        
        var combinations = [[Int]]()
        helper(1, [Int]())
        return combinations
    }
}
