class Vector2D {
    List<Integer> vect;
    int head;
    public Vector2D(int[][] v) {
        head = 0;
        vect = new ArrayList<Integer>();
        for (int[] nums : v) {
            for (int num : nums) {
                vect.add(num);
            }
        }
    }
    
    public int next() {
        return vect.get(head++);
    }
    
    public boolean hasNext() {
        return head < vect.size();
    }
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D obj = new Vector2D(v);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
