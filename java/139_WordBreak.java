class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        HashSet<String> wordSet = new HashSet<String>();
        for (String word : wordDict)
            wordSet.add(word);
        
        Deque<Integer> indices = new ArrayDeque<Integer>(){{
            addFirst(0);
        }};
        
        for (int i = 1; i <= s.length(); ++i) {
            for (int idx : indices) {
                if (wordSet.contains(s.substring(idx, i))){
                    indices.addFirst(i);
                    break;
                }
            }
        }
        return indices.getFirst() == s.length();
    }
}
