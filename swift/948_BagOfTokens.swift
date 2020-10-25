class Solution {
    func bagOfTokensScore(_ t: [Int], _ power: Int) -> Int {
        let tokens = t.sorted { $0 < $1 }
        var P = power
        if tokens.isEmpty || P < tokens[0] { return 0 }
        else if tokens.count == 1 { return P >= tokens[0] ? 1 : 0 }
        
        var left = 0, right = tokens.count - 1, score = 0
        while left < right {
            if tokens[left] <= P {
                while left < tokens.count && tokens[left] <= P {
                    P -= tokens[left]
                    left += 1
                    score += 1
                }
            } else if score > 0 {
                if left + 1 == right { break }
                P += tokens[right]
                right -= 1
                score -= 1
            }
        }
        return score
    }
}
