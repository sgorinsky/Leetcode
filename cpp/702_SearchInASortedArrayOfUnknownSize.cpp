/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0;
        int right = 2;
        while (reader.get(right) < target) right *= 2;
        while (left <= right) {
            int mid = (left + right) / 2;
            int num = reader.get(mid);
            if (num == target) return mid;
            
            int left_num = reader.get(left), right_num = reader.get(right);
            int diff = right - left;
            if (left == right && left_num != target) return -1;
            else if (left_num > target) {
                if (left <= 0 || left_num == INT_MAX) return -1;
                left -= diff / 2;
                right -= diff / 2;
            } else if (right_num < target) {
                while (right_num < target) {
                    if (right_num == target) return right;
                    right_num = reader.get(++right);
                }
                return -1;
            } else if (num > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
