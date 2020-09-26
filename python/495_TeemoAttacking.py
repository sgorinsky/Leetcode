class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        total_time, curr_overlap_end = 0, 0
        for t in timeSeries:
            total_time += min(t + duration - curr_overlap_end, duration)
            curr_overlap_end = t + duration
        return total_time
