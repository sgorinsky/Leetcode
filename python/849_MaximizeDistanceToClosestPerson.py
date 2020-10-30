class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        left, right, highest, N = 0, 0, 0, len(seats)
        while right < N and seats[right] != 1:
            right += 1
            highest += 1
        
        for i, seat in enumerate(seats):
            if seat == 1:
                left, right = i, i + 1
                while right < N and seats[right] != 1:
                    right += 1
                if right == N: return max(highest, right - 1 - i)
            else:
                highest = max(highest, min(i - left, right - i))
        return highest
