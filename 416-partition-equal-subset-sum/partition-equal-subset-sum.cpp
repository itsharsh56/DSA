class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum&1) return 0;
        int K=sum/2;
        bitset<10001> ans;
        ans[K]=1;
        for (int x: nums) {
            ans|= ans>>x;
            if (ans[0]) return 1;
        }
        return ans[0];
    }
};