class Solution {
    HashMap<String, Integer> wordCounts;
    public String[] uncommonFromSentences(String A, String B) {
        if (!A.isEmpty() && !B.isEmpty()){
            A += " " + B;
        } else {
            A = !A.isEmpty() ? A : B;
        }
        wordCounts = new HashMap<String, Integer>();
        List<String> words = splitBySpace(A);
        for (String word : words) {
            wordCounts.put(word, wordCounts.get(word) == null ? 1 : 2);
        }
        
        List<String> res = new ArrayList<String>();
        for (Map.Entry<String, Integer> entry : wordCounts.entrySet()) {
            if (entry.getValue() == 1) res.add(entry.getKey());
        }
        String[] resArray = new String[res.size()];
        for (int i = 0; i < resArray.length; ++i) resArray[i] = res.get(i);
        return resArray;
    }
    
    public List<String> splitBySpace(String str) {
        String curr = ""; int idx = 0;
        List<String> res = new ArrayList<String>();
        
        for (int i = 0; i < str.length(); ++i) {
            if (str.charAt(i) == ' ') {
                res.add(curr);
                curr = "";
            } else {
                curr += str.charAt(i);
            }
        }
        res.add(curr);
        return res;
    }
    
}
