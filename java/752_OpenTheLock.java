class Solution {
    public int openLock(String[] deadends, String target) {
        HashSet<String> deadSet = new HashSet<String>();
        for (String deadend : deadends) deadSet.add(deadend);
        
        HashSet<String> visitedSet = new HashSet<String>();
        Queue<String> q = new LinkedList();
        q.add("0000");
        q.add(null);
        
        int count = 0;
        while (!q.isEmpty()) {
            String currString = q.poll();
            
            if (currString == null) {
                count++;
                if (q.peek() != null) q.add(null);
            } else if (currString.equals(target)) {
                return count;
            } else if (!deadSet.contains(currString)) {
                for (int i = 0; i < currString.length(); ++i) {
                    for (int d = -1; d <= 1; d += 2) {
                        int charChange = ((currString.charAt(i) - '0') + d + 10) % 10;
                        String nextString = currString.substring(0, i) + ("" + charChange) + currString.substring(i+1);
                        if (!visitedSet.contains(nextString)) {
                            visitedSet.add(nextString);
                            q.add(nextString);
                        }
                    }
                }
            }
        }
        return -1;
    }
}
