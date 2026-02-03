class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int i = 0;

        // check for strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        if (i == 0) return false;

        // check for strictly decreasing
        int p = i;
        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
        if (i == p) return false;

        // check for strictly increasing
        int q = i;
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        if (i == q) return false;

        return i == n - 1;
    }
};
