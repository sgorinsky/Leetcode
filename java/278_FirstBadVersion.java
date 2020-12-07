/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            boolean bad = isBadVersion(mid);
            
            if (bad) right = mid;
            else left = mid + 1;
        }
        return left;
    }
}
