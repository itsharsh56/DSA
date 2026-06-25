class Solution {
public:
    long long totalHours(vector<int>& piles, int speed) {
        long long total = 0;
        for (int bananas : piles) {
            total += ceil((double)bananas / speed);
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // maximun element
        int maxi = *max_element(piles.begin(), piles.end());

        int low = 1, high = maxi;
        int ans = maxi;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = totalHours(piles, mid);

            // try smaller speed
            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            }
            // try larger speed
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};