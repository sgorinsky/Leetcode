class Solution {
    public int[] findPermutation(String s) {
        int N = s.length();
        int[] res = new int[N+1];
        
        for (int i = 0; i <= N; ++i)
            res[i] = i+1;
        
        int idx = 0;
        while (idx < N) {
            if (idx < N && s.charAt(idx) == 'D') {
                int start = idx;
                while (++idx < N && s.charAt(idx) == 'D');
                reverse(res, start, idx);
            } else {
                ++idx;
            }
        }
        return res;
    }
    
    public void reverse(int[] arr, int i, int j) {
        while (i <= j) {
            int temp = arr[i];
            arr[i++] = arr[j];
            arr[j--] = temp;
        }
    }
}
