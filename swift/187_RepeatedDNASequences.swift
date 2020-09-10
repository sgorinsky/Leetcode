class Solution {
    func findRepeatedDnaSequences(_ s: String) -> [String] {
        if s.count <= 10 { return [] }
        var sequences: [Substring : Int] = [Substring : Int]()
        var trail = s.startIndex, start = s.index(s.startIndex, offsetBy: 9)
        while start < s.endIndex {
            var substr = s[trail...start]
            sequences[substr, default: 0] += 1
            
            s.formIndex(after: &start)
            s.formIndex(after: &trail)
        }
        
        
        var result: [String] = [String]()
        sequences.forEach{
            k, v in
            if v > 1 { result.append(String(k)) }
        }
        
        return result
    }
}
