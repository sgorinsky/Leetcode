/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const { 
            auto hash1 = hash<T1>{}(p.first); 
            auto hash2 = hash<T2>{}(p.second); 
            return hash1 ^ hash2; 
        } 
    }; 
    
    unordered_set<pair<int, int>, hash_pair> visited_cells;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void cleanRoom(Robot& robot) {
        backtrack(robot, {0, 0}, 0);
    }
    
    void backtrack(Robot& robot, pair<int, int> cell, int direction) {
        visited_cells.insert(cell);
        robot.clean();
        
        for (int i = 0; i < 4; ++i) {
            int new_direction = (direction + i) % 4;
            pair<int, int> new_cell = {cell.first + directions[new_direction][0], cell.second + directions[new_direction][1]};
            if (visited_cells.find(new_cell) == visited_cells.end() && robot.move()) {
                backtrack(robot, new_cell, new_direction);
                go_back(robot);
            }
            robot.turnRight();
        }
    }
    void go_back(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
};
