class CombinationIterator {
    int[] nums;
    boolean has_next;
    int n, k;
    String chars;

    public CombinationIterator(String characters, int combinationLength) {
        n = characters.length();
        k = combinationLength;
        chars = characters;

        // init the first combination
        has_next = true;
        nums = new int[k];
        for (int i = 0; i < k; ++i) {
            nums[i] = i;
        }
    }

    public String next() {
        StringBuilder curr = new StringBuilder();
        for (int j: nums) {
            curr.append(chars.charAt(j));
        }

        // Generate next combination.
        // Find the first j such that nums[j] != n - k + j.
        // Increase nums[j] by one.
        int j = k - 1;
        while (j >= 0 && nums[j] == n - k + j) 
            --j;
        
        if (j >= 0) {
            nums[j]++;
            for (int i = j + 1; i < k; i++) {
                nums[i] = nums[j] + i - j;
            }
        } else {
            has_next = false;
        }

        return curr.toString();
    }

    public boolean hasNext() {
        return has_next;
    }
}
