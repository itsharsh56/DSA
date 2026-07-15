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

        int ans = 0;
        for (int bitIdx = 0; bitIdx < 32; bitIdx++) {
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] & (1 << bitIdx))
                count++;
            }
            if (count % 3 == 1) {
                ans = ans | (1 << bitIdx);
            }
        }
        return ans;
    }
};