class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        Arrays.sort(pieces, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[0] > b[0] ? 1 : -1;
            }
        });
        
        int i = 0;
        while (i < arr.length) {
            int start = arr[i];
            int left = 0, right = pieces.length - 1;
            int mid = (left + right) >> 1;
            while (left <= right) {
                mid = (left + right) >> 1;
                if (pieces[mid][0] == start) break;
                else if (pieces[mid][0] > start) right = mid - 1;
                else left = mid + 1;
            }
            for (int j = 0; j < pieces[mid].length; ++j) {
                if (arr[i++] != pieces[mid][j]) return false;
            }
        }
        return true;
    }
}
