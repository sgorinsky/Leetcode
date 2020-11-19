class Solution {
    var digits: Set<Character> = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
    func decodeString(_ s: String) -> String {
        var stack = [Character]()
        for c in s {
            if c != "]" {
                stack.append(c)
            } else {
                var currentString = [Character]()
                while !stack.isEmpty && stack.last! != "[" {
                    currentString.append(stack.removeLast())
                }
                stack.removeLast()
                
                var numRepeats = 0, base = 1
                while !stack.isEmpty && digits.contains(stack.last!) {
                    numRepeats += Int(String(stack.removeLast()))! * base
                    base *= 10
                }
                
                for i in 0..<numRepeats {
                    for (idx, c) in currentString.enumerated().reversed() {
                        stack.append(c)
                    }
                }
            }
        }
        return String(stack)
    }
}

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
