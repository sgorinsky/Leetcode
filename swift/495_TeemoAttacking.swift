class Solution {
    func findPoisonedDuration(_ timeSeries: [Int], _ duration: Int) -> Int {
        var totalTime: Int = 0, currEndOverlap: Int = 0
        for t in timeSeries {
            totalTime += min(t + duration - currEndOverlap, duration);
            currEndOverlap = t + duration;
        }
        return totalTime
    }
}
