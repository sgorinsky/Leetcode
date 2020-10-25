class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        Arrays.sort(tokens);
        if (tokens.length == 0 || P < tokens[0]) return 0;
        else if (tokens.length == 1) return P >= tokens[0] ? 1 : 0;
        
        int left = 0, right = tokens.length - 1, score = 0;
        while (left < right) {
            if (P >= tokens[left]) {
                while (left < tokens.length && P >= tokens[left]) {
                    P -= tokens[left++];
                    score++;
                }
            } else if (score > 0) {
                if (left + 1 == right) break;
                P += tokens[right--];
                score--;
            }
        }
        return score;
    }
}
