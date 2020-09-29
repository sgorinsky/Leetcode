class Solution {
    HashMap<Integer, Integer> cache;
    public int combinationSum4(int[] nums, int target) {
        cache = new HashMap<Integer, Integer>();
        return countCombinations(0, nums, target);
    }
    
    public int countCombinations(int sum, int[] nums, int target) {
        if (sum == target) 
            return 1;
        else if (sum > target)
            return 0;
        else if (cache.get(sum) != null)
            return cache.get(sum);
        
        int total = 0;
        for (int n : nums) {
            int currCombination = sum + n;
            if (cache.get(currCombination) == null) 
                cache.put(currCombination, countCombinations(currCombination, nums, target));
            total += cache.get(currCombination);
        }
        return total;
    }
}
