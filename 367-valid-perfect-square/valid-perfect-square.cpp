class Solution {
public:
    bool isPerfectSquare(int num) {

        if (num == 0 || num == 1)
            return true;

        int low = 0, high = num - 1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long check = mid * mid;
            if (check == num)
                return true;
            else if (check < num)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};