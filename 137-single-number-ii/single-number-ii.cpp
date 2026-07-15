class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // M-1 using map

        // unordered_map<int, int> mp;
        // for(auto :nums){
        //     mp[]++;
        // }
        // for(auto :mp){
        //     if(.second == 1){
        //         return .first;
        //     }
        // }

        // return -1;

        // M-2 using count the set bits

        // int ans = 0;
        // for (int bitIdx = 0; bitIdx < 32; bitIdx++) {
        //     int count = 0;
        //     for (int i = 0; i < nums.size(); i++) {
        //         if (nums[i] & (1 << bitIdx))
        //         count++;
        //     }
        //     if (count % 3 == 1) {
        //         ans = ans | (1 << bitIdx);
        //     }
        // }
        // return ans;

        // M-3 using sorting + iterate with 3

        int n = nums.size();
        // sort(nums.begin(), nums.end());

        // for (int i = 1; i < n; i += 3) {
        //     if (nums[i] != nums[i - 1])
        //         return nums[i - 1];
        // }
        // return nums[n - 1];

        // M-4 using concept of buckets

        int ones = 0, twos = 0;
        for(int i = 0; i < n; i++)
        {
            ones = (ones ^ nums[i]) & (~twos);
            twos = (twos ^ nums[i]) & (~ones);
        }
        return ones;
    }
};