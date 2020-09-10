class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        HashMap<String, Integer> seqs = new HashMap<String, Integer>();
        int trail = 0;
        for (int i = 9; i < s.length(); ++i) {
            String substr = s.substring(trail, i+1);
            
            int n = seqs.getOrDefault(substr, 0);
            seqs.put(substr, n + 1);
            ++trail;
        }
        
        List<String> result = new ArrayList<String>();
        seqs.forEach((k, v) -> {
            if (v > 1)
                result.add(k);
        });
        return result;
    }
}
