class Solution {
    func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool {
        func binarySearchRow(_ row: [Int]) -> Bool {
            var left = 0, right = row.count - 1
            while left <= right {
                var mid = left + (right - left) / 2
                if row[mid] == target { return true }
                else if row[mid] < target { left = mid + 1 }
                else { right = mid - 1 }
            }
            return false
        }
        for row in matrix {
            if binarySearchRow(row) { return true }
        }
        return false
    }
}
