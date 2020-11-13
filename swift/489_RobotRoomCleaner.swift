/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * public class Robot {
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     public func move() -> Bool {}
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     public func turnLeft() {}
 *     public func turnRight() {}
 *
 *     // Clean the current cell.
 *     public func clean() {}
 * }
 */

class Solution {
    struct Cell : Hashable {
        let x: Int
        let y: Int
        init(_ x: Int, _ y: Int) {
            self.x = x
            self.y = y
        }
    }

    func cleanRoom(_ robot: Robot) {
        func goBack() {
            robot.turnRight()
            robot.turnRight()
            robot.move()
            robot.turnRight()
            robot.turnRight()
        }
        
        func backtrack(_ cell: Cell, _ direction: Int) {
            visitedCells.insert(cell)
            robot.clean()
            for i in 0..<4 {
                var newDirection = (direction + i) % 4
                var newCell = Cell(cell.x + directions[newDirection].0, cell.y + directions[newDirection].1)
                if !visitedCells.contains(newCell) && robot.move() {
                    backtrack(newCell, newDirection)
                    goBack()
                }
                // turn the robot following chosen direction : clockwise
                robot.turnRight()
            }
        }
        
        var visitedCells = Set<Cell>()
        var directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        backtrack(Cell(0, 0), 0)
    }
}
