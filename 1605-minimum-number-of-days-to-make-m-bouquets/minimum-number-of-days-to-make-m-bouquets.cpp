class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int n = bloomDay.size();
        int cnt = 0;
        int bouquets = 0;

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                // bloomed, increase count
                cnt++;
                if (cnt == k) {
                    bouquets++;
                    cnt = 0; // reset
                }
            } else {
                // not bloomed, reset count to zero
                cnt = 0;
            }
        }

        // Check if at least m bouquets make
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long total = 1LL * k * m;
        if (total > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        // int low = mini, high = maxi;
        // int result = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (possible(bloomDay, mid, m, k)) {
                // result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // return result;
        return low; 
    }
};