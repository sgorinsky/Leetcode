class Solution {
    public boolean validMountainArray(int[] arr) {
        if (arr.length < 3 || arr[0] > arr[1]) return false;
        boolean increasing = true;
        for (int i = 0; i < arr.length - 1; ++i) {
            if (arr[i] == arr[i + 1]) return false;
            if (increasing) {
                if (arr[i] > arr[i + 1]) increasing = false;
            } else {
                if (arr[i] < arr[i+1]) return false;
            }
        }
        return !increasing;
    }
}
