class Solution {
    func numDecodings(_ s: String) -> Int {
        func helper(_ idx: String.Index) -> Int {
            if let entry = cache[idx] { return entry }
            else if idx == s.endIndex { return 1 }
            else if idx > s.endIndex || s[idx] == "0" { return 0 }
            
            cache[idx] = helper(s.index(idx, offsetBy: 1))
            if s.count > 1 && idx <= s.index(s.endIndex, offsetBy: -2) {
                var idxByTwo = s.index(idx, offsetBy: 2)
                var n = Int(String(s[idx..<idxByTwo]))!
                if n >= 0 && n <= 26 {
                    cache[idx]! += helper(idxByTwo)
                }
            }
            return cache[idx]!
        }
        
        var cache = [String.Index:Int]()
        return helper(s.startIndex)
    }
}
