class Solution {
    let vowels: Set<Character> = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
    func toGoatLatin(_ S: String) -> String {
        var res: String = "", suffix: String = ""

        for currString in S.components(separatedBy: " ") {
            var curr = currString
            suffix += "a"
            if !vowels.contains(curr[curr.startIndex]) {
                let firstIdx = curr.index(curr.startIndex, offsetBy: 1)
                curr = "\(curr.substring(from: firstIdx))\(curr[curr.startIndex])"
            }
            res += curr + "ma" + suffix + " "
        }
        return String(res.dropLast())
    }
}
