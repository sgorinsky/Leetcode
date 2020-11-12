class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        
        def get_dist(a, b):
            return (b[1] - a[1]) * (b[1] - a[1]) + (b[0] - a[0]) * (b[0] - a[0])
        
        points = [p1, p2, p3, p4]
        distance_set = {get_dist(points[i], points[j]) for i in range(len(points)) for j in range(i+1, len(points))}
        
        return len(distance_set) == 2 and 0 not in distance_set
