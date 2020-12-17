class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int left = 0, right = arr.length - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] <= arr[mid + k] - x) right = mid;
            else left = mid + 1;
        }
        return new ArrayList<Integer>(Arrays.stream(Arrays.copyOfRange(arr, left, left + k)).boxed().collect(Collectors.toList()));
    }
}
