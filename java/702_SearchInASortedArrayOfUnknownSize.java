/**
 * // This is ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *     public int get(int index) {}
 * }
 */

class Solution {
    public int search(ArrayReader reader, int target) {
        int left = 0, right = 10000;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int n = reader.get(mid);
            
            if (n == target) return mid;
            else if (n < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
}

/**
 * // This is ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *     public int get(int index) {}
 * }
 */

class Solution {
    public int search(ArrayReader reader, int target) {
        if (reader.get(0) == target) return 0;
        
        int left = 0, right = 1;
        while (reader.get(right) < target) {
            left = right;
            right <<= 1;
        }
        while (left <= right) {
            int mid = (left + right) >> 1;
            int num = reader.get(mid);
            
            if (num == target) return mid;
            else if (num < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
}
