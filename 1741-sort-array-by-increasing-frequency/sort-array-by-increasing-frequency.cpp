class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        // M-1 using heap
        // priority_queue<pair<int, int>, vector<pair<int, int>>,
        //                greater<pair<int, int>>>
        //     minHeap;

        // for (auto i : mp) {
        //     minHeap.push({i.second, -i.first});
        // }

        // vector<int> ans;

        // while (minHeap.size() > 0) {
        //     int count = minHeap.top().first;
        //     int num = -minHeap.top().second;

        //     while (count--) {
        //         ans.push_back(num);
        //     }
        //     minHeap.pop();
        // }
        // return ans;

        // M-2 using sort + comparator
        sort(nums.begin(), nums.end(), [&](int n1, int n2) {
            if (mp[n1] != mp[n2]) {
                return mp[n1] < mp[n2];
            } else {
                return n2 < n1;
            }
        });

        return nums;
    }
};