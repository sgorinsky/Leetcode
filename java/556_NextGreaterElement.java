class Solution {
    public int nextGreaterElement(int n) {
        List<Integer> digits = new ArrayList<Integer>();
        while (n > 0) {
            digits.add(n % 10);
            n /= 10;
        }
        
        boolean switched = false;
        int sz = digits.size();
        for (int i = 0; i < sz - 1; ++i) {
            if (digits.get(i + 1) < digits.get(i)) {
                switched = true;
                
                // i+1 switch with beginning
                int temp = digits.get(i + 1);
                int begin = 0;
                while (digits.get(begin) == 0 || digits.get(begin) <= temp) begin++;
                
                digits.set(i + 1, digits.get(begin));
                digits.set(begin, temp);
                
                // reverse subarray 0 to i
                int j = 0;
                while (i > j) {
                    temp = digits.get(i);
                    digits.set(i--, digits.get(j));
                    digits.set(j++, temp);
                }
                break;
            }
        }
        
        if (!switched) return -1;
        while (!digits.isEmpty()) {
            if (n > Integer.MAX_VALUE / 10) return -1;
            n *= 10;
            n += digits.remove(digits.size() - 1);
        }
        return n;
    }
}
