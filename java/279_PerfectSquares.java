class Solution {
    public int numSquares(int n) {
        List<Integer> squares = new ArrayList<Integer>();
        int size = 0;
        for (int i = 1; i*i <= n; ++i) {
            squares.add(i*i);
            if (squares.get(size++) == n) return 1;
        }
        
        int count = n;
        while (size > 1) {
            for (int i = size - 1; i > 0; --i) {
                int candidate = squares.get(size - 1), currCount = 1, head = i;
                while (candidate < n && currCount < count) {
                    if (candidate + squares.get(head) == n) {
                        count = Math.min(currCount + 1, count);
                        break;
                    } else if (candidate + squares.get(head) > n) {
                        --head;
                    } else {
                        currCount++;
                        candidate += squares.get(head);
                    }
                }
            }
            squares.remove(--size);
        }
        return count;
    }
}
