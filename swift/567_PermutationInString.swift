class Solution {
    func checkInclusion(_ s1: String, _ s2: String) -> Bool {
        let M = s1.count
        let N = s2.count
        if M > N {
            return false;
        }
        
        let offset: UInt8 = Character("a").asciiValue!
        
        var m_counts: [Int] = Array(repeating: 0, count: 26)
        for c in s1 {
            m_counts[Int(c.asciiValue! - offset)] += 1
        }
        
        var n_counts: [Int] = Array(repeating: 0, count: 26)
        for c in s2.prefix(M) {
            n_counts[Int(c.asciiValue! - offset)] += 1
        }
        
        var trailingIdx = s2.index(s2.startIndex, offsetBy: 0)
        var trailingChar: Character = s2[trailingIdx]

        let startIndex = s2.index(s2.startIndex, offsetBy: M)
        let endIndex = s2.index(s2.startIndex, offsetBy: N)
        let substr = String(s2[startIndex..<endIndex])
        for c in substr {
            if n_counts == m_counts {
                return true
            }
            n_counts[Int(c.asciiValue! - offset)] += 1
            n_counts[Int(trailingChar.asciiValue! - offset)] -= 1
            
            // Use indexes to access chars in string
            trailingIdx = s2.index(after: trailingIdx)
            trailingChar = s2[trailingIdx]
        }
        return n_counts == m_counts
    }
}
