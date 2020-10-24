class Solution {
    func dailyTemperatures(_ T: [Int]) -> [Int] {
        var results = T.map {(temp) in return 0 }
        var stack = [(idx: Int, temp: Int)]()
        
        for (i, temp) in T.enumerated() {
            if !stack.isEmpty && stack.last!.temp < temp {
                while !stack.isEmpty && stack.last!.temp < temp {
                    results[stack.last!.idx] = i - stack.last!.idx
                    stack.removeLast()
                }
            }
            stack.append((idx: i, temp: temp))
        }
        return results
    }
}
