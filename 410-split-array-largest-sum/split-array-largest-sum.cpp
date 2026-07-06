class Solution {
public:
    int countPartitions(const vector<int>& nums, int maxSum) {
        int split = 1;
        long long sum = 0; 

        for (int num : nums) {
            if (sum + num <= maxSum) {
                sum += num;
            } else {
             split++;
                sum = num;
            }
        }
        return split;
    }


    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int split = countPartitions(nums, mid);

            if  (split > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};