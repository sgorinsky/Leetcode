class RecentCounter {
    Deque<Integer> calls;
    public RecentCounter() {
        calls = new ArrayDeque<Integer>();
    }
    
    public int ping(int t) {
        while (!calls.isEmpty() && calls.getFirst() < t - 3000)
            calls.pollFirst();
        calls.add(t);
        return calls.size();
    }
}
