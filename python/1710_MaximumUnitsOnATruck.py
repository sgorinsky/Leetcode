class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        q = deque(sorted(boxTypes, key=lambda x: -x[1]))
        units = 0
        while q and truckSize > 0:
            box = q.popleft()
            units += min(truckSize, box[0]) * box[1]
            truckSize -= box[0]
        return units

class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: x[1])
        units = 0
        while boxTypes and truckSize > 0:
            box = boxTypes.pop()
            units += min(truckSize, box[0]) * box[1]
            truckSize -= box[0]
        return units
