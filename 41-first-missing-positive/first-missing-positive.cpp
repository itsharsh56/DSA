class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int x = 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == x) {
                ++x;
            } else if (nums[i] > x) {
                return x;
            }
        }
        return x;
    }
};