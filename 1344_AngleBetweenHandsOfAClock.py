class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        hour_degrees = hour%12*5 + minutes/12
        absolute_degrees = abs(hour_degrees-minutes)*6
        return min(360-absolute_degrees, absolute_degrees)
