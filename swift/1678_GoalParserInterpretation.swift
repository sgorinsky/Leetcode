class Solution {
    func interpret(_ command: String) -> String {
        var i = 0
        var idx = command.startIndex
        var result = ""
        while i < command.count {
            if command[idx] == "G" {
                result.append("G")
                i += 1
                idx = command.index(after: idx)
            } else if command[command.index(after: idx)] == ")" {
                result.append("o")
                i += 2
                idx = command.index(idx, offsetBy: 2)
            } else {
                result.append("al")
                i += 4
                idx = command.index(idx, offsetBy:4)
            }
        }
        return result
    }
}
