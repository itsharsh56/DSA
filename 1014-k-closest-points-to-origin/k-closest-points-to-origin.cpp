class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;

        for(auto i : points)
        {
            long long x = i[0];
            long long y = i[1];
            long long d = ((x * x) + (y * y));

            maxHeap.push({d,i});

            if(maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        vector<vector<int>> ans;

        while(maxHeap.size() > 0)
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};