class Solution {
    func maximumUnits(_ boxTypes: [[Int]], _ truckSize: Int) -> Int {
        var boxes = boxTypes.sorted() { $0[1] > $1[1] }
        var totalUnits = 0, currentSize = truckSize, idx = 0, N = boxes.count
        while idx < N && currentSize > 0 {
            var box = boxes[idx]
            totalUnits += (currentSize > box[0] ? box[0] : currentSize) * box [1]
            currentSize -= box[0]
            idx += 1
        }
        return totalUnits
    }
}
