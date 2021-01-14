class Solution {
    func numRescueBoats(_ people: [Int], _ limit: Int) -> Int {
        var weights = people.sorted() { $0 < $1 }
        var i = 0, j = weights.count - 1
        var boats = 0
        while i <= j {
            while i < j && weights[i] + weights[j] > limit {
                j -= 1
                boats += 1
            }
            boats += 1
            i += 1
            j -= 1
        }
        return boats
    }
}
