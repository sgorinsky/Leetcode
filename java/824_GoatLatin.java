class Solution {
    private static Set<Character> vowels =
            new HashSet<>() {
                {
                    add('a');
                    add('e');
                    add('i');
                    add('o');
                    add('u');
                    add('A');
                    add('E');
                    add('I');
                    add('O');
                    add('U');
                }
            };

    public String toGoatLatin(String S) {
        String suff = "";
        StringBuilder res = new StringBuilder();
        
        for (String curr : S.split(" ")) {
            suff += 'a';
            
            if (!vowels.contains(curr.charAt(0)))
                curr = curr.substring(1) + curr.charAt(0);
            
            res.append(curr).append("ma").append(suff).append(' ');
        }
        
        res.deleteCharAt(res.length() - 1);
        return res.toString();
    }
}
