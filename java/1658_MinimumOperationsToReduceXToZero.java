class Solution {
    public int minOperations(int[] nums, int x) {
        int N = nums.length, count = Integer.MAX_VALUE, curr = 0;
        int i = -1;
        while (curr < x && ++i < N) 
            curr += nums[i];
        
        if (curr == x) 
            count = i + 1;
        else if (i >= N) 
            return -1;
        
        for (int j = N - 1; j >= 0; --j) {
            curr += nums[j];
            while (curr > x && i >= 0)
                curr -= nums[i--];
            
            if (curr == x)
                count = Math.min(count, i + N - j + 1);
            else if (curr > x && i < 0)
                break;
        }
        return count == Integer.MAX_VALUE ? -1 : count;
    }
}
