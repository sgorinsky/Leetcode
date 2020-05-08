class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        if len(coordinates) <= 2: return True
        
        m = self.findSlope(coordinates[0], coordinates[1])
        b = coordinates[0][1] - coordinates[0][0]*m
        
        for coord in coordinates:
            if coord[1] != coord[0]*m + b:
                return False
        return True
    
    def findSlope(self, c1, c2):
        if c2[0] == c1[0]:
            return float('inf')
        return (c2[1] - c1[1])/(c2[0]-c1[0])
