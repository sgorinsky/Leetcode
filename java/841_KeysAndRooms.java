class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        if (rooms.isEmpty()) return false;
        HashSet<Integer> roomsNotVisited = new HashSet<Integer>(){{
            for (int i = 1; i < rooms.size(); ++i) {
                add(i);
            };
        }};
        
        Queue<List<Integer>> q = new LinkedList<List<Integer>>();
        q.add(rooms.get(0));
        
        while (!q.isEmpty()) {
            List<Integer> keys = q.poll();
            for (int k : keys) {
                if (roomsNotVisited.contains(k)) {
                    q.add(rooms.get(k));
                    roomsNotVisited.remove(k);
                }
            }
            if (roomsNotVisited.isEmpty()) return true;
        }
        return false;
    }
}
