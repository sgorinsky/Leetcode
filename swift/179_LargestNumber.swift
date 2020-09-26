class Solution {
    func largestNumber(_ nums: [Int]) -> String {
        var numStrings: [String] = nums.map({ (num: Int) -> String in
            return String(num)
        }).sorted(by: { (a: String, b: String) -> Bool in
            return a + b > b + a
        })
        
        return numStrings[0] == "0" ? "0" : numStrings.reduce("", +)
    }
}

class Solution {
    func largestNumber(_ nums: [Int]) -> String {
        var numStrings: [String] = nums.map({ (num: Int) -> String in
            return String(num)
        })
        numStrings.sort(by: { (a: String, b: String) -> Bool in
            return a + b > b + a
        })
        
        if numStrings[0] == "0" { return "0" }
        return numStrings.reduce("", +)
    }
}
