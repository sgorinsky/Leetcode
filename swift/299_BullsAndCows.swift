class Solution {
    func getHint(_ secret: String, _ guess: String) -> String {
        var counts: [Character : Int] = [Character : Int]()
        
        var bulls: Int = 0, cows: Int = 0
        
        var index = secret.startIndex
        while index != secret.endIndex {
            var s: Character = secret[index], g: Character = guess[index]
            if s == g {
                bulls += 1
            } else {
                if counts[s, default: 0] < 0 { cows += 1 }
                if counts[g, default: 0] > 0 { cows += 1 }
                
                counts[s, default: 0] += 1
                counts[g, default: 0] -= 1
            }
            secret.formIndex(after: &index)
        }
        return "\(bulls)A\(cows)B"
    }
}
