class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        // Determine the maximum frequency
        int maxcount = 0;
        for (auto [num, freq] : count) {
            maxcount = max(maxcount, freq);
        }

        // Calculate the total frequencies of elements with the maximum frequency
        int ans = 0;
        for (auto [num, freq] : count) {
            if (freq == maxcount) {
                ans++;
            }
        }
        return ans * maxcount;
    }
};