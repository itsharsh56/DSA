class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, curr_or = 0, max_len = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while ((curr_or & nums[right]) != 0) {
                curr_or ^= nums[left]; 
                left++;                
            }

            curr_or |= nums[right];

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};