class Solution {
    func validSquare(_ p1: [Int], _ p2: [Int], _ p3: [Int], _ p4: [Int]) -> Bool {
        func calculateDistanceBetweenTwoPoints(_ a: [Int], _ b: [Int]) -> Int {
            return (b[1] - a[1]) * (b[1] - a[1]) + (b[0] - a[0]) * (b[0] - a[0])
        }
        
        var points = [p1, p2, p3, p4]
        var distances = Set<Int>()
        
        for i in 0..<points.count {
            for j in i+1..<points.count {
                if points[i] == points[j] {
                    return false
                }
                distances.insert(calculateDistanceBetweenTwoPoints(points[i], points[j]))
            }
        }
        return distances.count == 2
    }
}
