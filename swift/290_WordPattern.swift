class Solution {
    func wordPattern(_ pattern: String, _ str: String) -> Bool {
        var separatedStr: [String] = str.components(separatedBy: " ")
        
        if str == " " && pattern.count == 1 { return true }
        else if separatedStr.count != pattern.count || pattern == "" || str == "" { return false }
        
        var charMappings: [Character : String] = [Character : String]()
        var wordMappings: [String : Character] = [String : Character]()
                
        for (i, c) in pattern.enumerated() {
            if let word = charMappings[c] {
                if word != separatedStr[i] { return false }
            } else if let char = wordMappings[separatedStr[i]] {
                if char != c { return false }
            } else {
                charMappings[c] = separatedStr[i]
                wordMappings[separatedStr[i]] = c
            }
        }
        return true
    }
}
