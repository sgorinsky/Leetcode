class Solution {
    public int[] sortArrayByParity(int[] A) {
        int frontIdx = 0, backIdx = A.length-1;
        int[] res = new int[A.length];
        
        for (int n : A) 
            res[n % 2 == 0 ? frontIdx++ : backIdx--] = n;
        
        return res;
    }
}
