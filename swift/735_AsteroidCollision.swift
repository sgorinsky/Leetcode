class Solution {
    func asteroidCollision(_ asteroids: [Int]) -> [Int] {
        var stack = [Int]()
        for asteroid in asteroids {
            var brokeFromWhile = false
            while !stack.isEmpty && asteroid < 0 && stack.last! > 0 {
                if -asteroid > stack.last! {
                    stack.removeLast()
                    continue
                } else if -asteroid == stack.last! {
                    stack.removeLast()
                }
                brokeFromWhile = true
                break;
            }
            if !brokeFromWhile {
                stack.append(asteroid)
            }
        }
        return stack
    }
}
