class Solution {
    func distributeCandies(_ candies: Int, _ num_people: Int) -> [Int] {
        var candies = candies
        var people: [Int] = [Int](repeating: 0, count: num_people)
        var i: Int = 1
        
        var index = people.index(people.startIndex, offsetBy: 0)
        while candies > 0 {
            people[index] += candies >= i ? i : candies
            candies -= i
            index = i % num_people == 0 ? people.index(people.startIndex, offsetBy: 0) : people.index(after: index)
            i += 1
        }
        return people
    }
}
