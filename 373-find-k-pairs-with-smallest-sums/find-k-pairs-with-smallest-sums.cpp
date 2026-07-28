class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        for (int a : nums1) {
            for (int b : nums2) {

                int sum = a + b;

                if (maxHeap.size() < k) {
                    maxHeap.push({sum, {a, b}});
                } 
                else if (sum < maxHeap.top().first) {
                    maxHeap.pop();
                    maxHeap.push({sum, {a, b}});
                }
                else {
                    break;
                }
            }
        }
        vector<vector<int>> ans;

        while (maxHeap.size() > 0) {
            ans.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};