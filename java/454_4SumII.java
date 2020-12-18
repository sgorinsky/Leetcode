class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        HashMap<Integer, Integer> sums = new HashMap<Integer, Integer>();
        for (int a : A) {
            for (int b : B)
                sums.put(a + b, sums.getOrDefault(a + b, 0) + 1);
        }
        
        int count = 0;
        for (int c : C) {
            for (int d : D)
                count += sums.getOrDefault(-(c + d), 0);
        }
        return count;
    }
}

class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int[][] arrs = {A, B, C, D};
        HashMap<Integer, Integer> sums = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> nextSums;
        
        for (int n : arrs[0])
            sums.put(n, sums.getOrDefault(n, 0) + 1);

        for (int i = 1; i < arrs.length - 1; ++i) {
            nextSums = new HashMap<Integer, Integer>();
            for (int k : sums.keySet()) {
                int count = sums.get(k);
                for (int n : arrs[i])
                    nextSums.put(k + n, nextSums.getOrDefault(k + n, 0) + count);
            }
            sums = nextSums;
        }
        
        int count = 0;
        for (int n : arrs[arrs.length - 1])
            if (sums.get(-n) != null) 
                count += sums.get(-n);

        return count;
    }
}

class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int[][] arrs = {A, B, C, D};
        HashMap<Integer, Integer> sums = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> nextSums;
        for (int n : arrs[0])
            sums.put(n, sums.getOrDefault(n, 0) + 1);

        for (int i = 1; i < arrs.length; ++i) {
            nextSums = new HashMap<Integer, Integer>();
            for (int k : sums.keySet()) {
                int count = sums.get(k);
                for (int n : arrs[i])
                    nextSums.put(k + n, nextSums.getOrDefault(k + n, 0) + count);
            }
            sums = nextSums;
        }
        return sums.getOrDefault(0, 0);
    }
}
