class Solution {
    func findPermutation(_ str: String) -> [Int] {
        var s = str
        var stack: [Int] = [Int](), res: [Int] = [Int]()
        var stringIdx = s.index(s.startIndex, offsetBy: 0)
        var N = s.count
        
        for i in 0...N {
            if i == N || s[stringIdx] == "I" {
                res.append(i+1)
                while !stack.isEmpty { res.append(stack.popLast()!) }
            } else {
                stack.append(i+1)
            }
            if i < N { s.formIndex(after: &stringIdx) }
        }
        return res
    }
}
