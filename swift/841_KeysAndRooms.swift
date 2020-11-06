class Solution {
    func canVisitAllRooms(_ rooms: [[Int]]) -> Bool {
        if rooms.isEmpty { return false }
        
        var checkedRooms = [Bool](repeating: false, count: rooms.count)
        checkedRooms[0] = true
        var countedRooms = 1
        
        var stack = [[Int]]()
        stack.append(rooms[0])
        while !stack.isEmpty {
            var keys = stack.removeLast()
            for key in keys {
                if !checkedRooms[key] {
                    stack.append(rooms[key])
                    checkedRooms[key] = true
                    countedRooms += 1
                }
            }
            if countedRooms == checkedRooms.count { return true }
        }
        return false
    }
}
