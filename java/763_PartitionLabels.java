class Solution {
    public List<Integer> partitionLabels(String s) {
        Map<Character, Integer> lastIndices = new HashMap<Character, Integer>();
        
        for (int i = 0; i < s.length(); ++i)
            lastIndices.put(s.charAt(i), i);
        
        List<Integer> partitions = new ArrayList<Integer>();
        int curr = lastIndices.get(s.charAt(0));
        int last = 0;
        for (int i = 0; i < s.length(); ++i) {
            int lastIdx = lastIndices.get(s.charAt(i));
            curr = lastIdx > curr ? lastIdx : curr;
            if (i == curr) {
                partitions.add(curr - last + 1);
                last = curr + 1;
            }
        }
        return partitions;
    }
}
