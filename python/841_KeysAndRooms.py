class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        if not rooms: return False
        
        visited_rooms = [False for i in range(len(rooms))]
        visited_rooms[0] = True
        counted_rooms = 1
        
        stack = [rooms[0]]
        while stack:
            keys = stack.pop()
            for key in keys:
                if not visited_rooms[key]:
                    stack.append(rooms[key])
                    visited_rooms[key] = True
                    counted_rooms += 1
            if counted_rooms == len(visited_rooms):
                return True
        return False
        
