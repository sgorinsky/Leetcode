class Solution {
    func decodeString(_ s: String) -> String {
        var stack = [String]()
        var idx = s.startIndex
        while idx != s.endIndex {
            var currChar = String(s[idx])
            if currChar == "]" {
                var currentString = ""
                while !stack.isEmpty && stack.last != "[" {
                    currentString.append(stack.removeLast())
                }
                stack.removeLast() // pop "["
                
                var k = ""
                while !stack.isEmpty && stack.last!.count == 1 && Character(stack.last!).isNumber {
                    k = "\(stack.removeLast())\(k)"
                }
                
                var n = Int(k) ?? 0
                for i in 0..<n {
                    stack.append(currentString)
                }
            } else {
                stack.append(currChar)
            }
            idx = s.index(after: idx)
        }
        var result = ""
        for (i, word) in stack.enumerated() {
            for (i, c) in word.enumerated().reversed() {
                result.append(c)
            }
        }
        return result
    }
}
