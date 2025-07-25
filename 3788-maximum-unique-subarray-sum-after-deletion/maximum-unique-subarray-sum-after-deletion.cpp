class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool neg = true;
        int max = INT_MIN;

        for (int n : nums) {
            if (n >= 0) neg = false;
            if (n > max) max = n;
        }
        if (neg) return max;

        unordered_set<int> unique(nums.begin(), nums.end());

        int sum = 0;
        for (int val : unique) {
            if (val > 0) sum += val;
        }

        return sum;
    }
};
