class Solution {
    func reformatNumber(_ number: String) -> String {
        var output = [String]()
        var num = number.replacingOccurrences(of: #"[\s-]"#, with: "", options: .regularExpression)
        
        var i = 0
        var idx = num.startIndex
        while i < num.count {
            var next = ""
            if i + 4 == num.count {
                for j in i..<i+2 {
                    next.append(num[idx])
                    idx = num.index(after: idx)
                }
                i += 2
                output.append(next)
            } else if i + 3 <= num.count {
                for j in i..<i+3 {
                    next.append(num[idx])
                    idx = num.index(after: idx)
                }
                i += 3
                output.append(next)
            } else {
                for j in i..<i+2 {
                    next.append(num[idx])
                    idx = num.index(after: idx)
                }
                i += 2
                output.append(next)
            }
        }
        
        return output.count == 1 ? output[0] : output.joined(separator: "-")
    }
}
