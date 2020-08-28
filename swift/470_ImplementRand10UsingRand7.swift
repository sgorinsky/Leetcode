/**
 * The rand7() API is already defined in the parent class SolBase.
 * func rand7() -> Int = {}
 * @return a random integer in the range 1 to 7
 */
class Solution : SolBase {
    func rand10() -> Int {
        var rand: Int = 0
        for _ in 1...10 {
            rand += rand7()
        }
        return rand % 10 + 1
    }
}
