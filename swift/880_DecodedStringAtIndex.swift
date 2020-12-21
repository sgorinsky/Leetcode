class Solution {
    func decodeAtIndex(_ S: String, _ K: Int) -> String {
        var k = K
        var size = 0
        for c in S {
            if c.isNumber {
                size *= Int(String(c))!
            } else {
                size += 1
            }
        }
        
        for (i, c) in S.enumerated().reversed() {
            k %= size
            if c.isNumber {
                size /= Int(String(c))!
            } else {
                if k == 0 {
                    return String(c)
                }
                size -= 1
            }
        }
        return String(S[S.startIndex])
    }
}
