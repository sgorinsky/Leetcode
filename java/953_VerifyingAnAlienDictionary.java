class Solution {
    HashMap<Character, Integer> orderDict;
    public boolean isAlienSorted(String[] words, String order) {
        orderDict = new HashMap<Character, Integer>();
        for (int i = 0; i < order.length(); ++i) {
            orderDict.put(order.charAt(i), i);
        }
        
        String prev = words[0];
        for (int i = 1; i < words.length; ++i) {
            if (!check(prev, words[i])) return false;
            prev = words[i];
        }
        return true;
    }
    
    public boolean check(String w1, String w2) {
        if ((w1.isEmpty() || w2.isEmpty())) {
            return w1.length() <= w2.length();
        } else if (orderDict.get(w1.charAt(0)) < orderDict.get(w2.charAt(0))) {
            return true;
        } else if (orderDict.get(w1.charAt(0)) > orderDict.get(w2.charAt(0))) {
            return false;
        } else {
            return check(w1.substring(1, w1.length()), w2.substring(1, w2.length()));
        }
    }
}
