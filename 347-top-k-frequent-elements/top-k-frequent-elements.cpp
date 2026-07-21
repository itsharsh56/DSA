class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;

            for(int i = 0; i < n;i++)
            {
                mp[nums[i]]++;
            }

            for(auto i : mp)
            {
                minHeap.push({i.second, i.first});

                if(minHeap.size() > k)
                {
                    minHeap.pop();
                }
            }

            while(minHeap.size() > 0)
            {
                ans.push_back(minHeap.top().second);
                minHeap.pop();
            }
            return ans;
    }
};