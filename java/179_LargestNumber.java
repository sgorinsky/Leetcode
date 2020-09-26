class Solution {
    private class LargerNumberComparator implements Comparator<String> {
        @Override
        public int compare(String a, String b) {
            String order1 = a + b;
            String order2 = b + a;
           return order2.compareTo(order1);
        }
    }

    public String largestNumber(int[] nums) {
        String[] numStrings = new String[nums.length];
        
        for (int i = 0; i < nums.length; ++i)
            numStrings[i] = String.valueOf(nums[i]);
        
        Arrays.sort(numStrings, new LargerNumberComparator());
        if (numStrings[0].equals("0"))
            return "0";
        
        StringBuilder result = new StringBuilder();
        for (String s : numStrings)
            result.append(s);
        
        return result.toString();
    }
}
