class Solution {
    func carPooling(_ trips: [[Int]], _ capacity: Int) -> Bool {
        var buckets = [Int](repeating: 0, count: 1001)
        for trip in trips {
            buckets[trip[1]] += trip[0] // start of passenger pickup
            buckets[trip[2]] -= trip[0] // end of passenger pickup
        }

        var totalCurrCapacity: Int = 0
        for numPeople in buckets {
            totalCurrCapacity += numPeople
            if totalCurrCapacity > capacity { return false }
        }
        return true
    }
}
