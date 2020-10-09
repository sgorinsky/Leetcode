class TwoSum {
    var numCounts = [Int : Int]()
    
    /** Add the number to an internal data structure.. */
    func add(_ num: Int) {
        if numCounts[num] != nil {
            numCounts[num]! += 1
        } else {
            numCounts[num] = 1
        }
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    func find(_ value: Int) -> Bool {
        for (num, numCount) in numCounts {
            if value == 0 {
                if (num != 0 && numCounts[-num] ?? 0 != 0) || numCounts[0] ?? 0 > 1 { return true }
            } else if numCounts[value - num] ?? 0 > 0 {
                if value - num == num { 
                    if numCount > 1 { return true }
                    else { continue }
                }
                return true
            }
        }
        return false
    }
}

class TwoSum {
    var numCounts = [Int : Int]()
    var nums = [Int]()
    
    /** Add the number to an internal data structure.. */
    func add(_ num: Int) {
        if numCounts[num] != nil {
            numCounts[num]! += 1
        } else {
            numCounts[num] = 1
        }
        nums.append(num)
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    func find(_ value: Int) -> Bool {
        for num in nums {
            if value == 0 {
                if (num != 0 && (numCounts[-num] ?? 0) != 0) || (numCounts[0] ?? 0) > 1 { return true }
            } else if numCounts[value - num] != nil {
                if value - num == num { return (numCounts[num] ?? 0) > 1 }
                return true
            }
        }
        return false
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * let obj = TwoSum()
 * obj.add(number)
 * let ret_2: Bool = obj.find(value)
 */
