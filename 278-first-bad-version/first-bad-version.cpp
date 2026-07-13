// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                high = mid; // First bad is at mid ya usse phle
            }

            else {
                low = mid + 1; // First bad is after mid
            }
        }
        return low;
    }
};