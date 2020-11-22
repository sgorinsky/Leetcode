class Solution {
    func getSmallestString(_ n: Int, _ k: Int) -> String {
        var chars = [Character](repeating: "a", count: n)
        var score = n
        var end = n - 1
        
        while score < k {
            if k - score >= 26 {
                chars[end] = "z"
                end -= 1
                score += 25
            } else if k - score < 26 {
                var changedCharacter = Int(("a" as UnicodeScalar).value) + k - score
                chars[end] = Character(UnicodeScalar(changedCharacter)!)
                break;
            }
        }
        
        return String(chars)
    }
}
